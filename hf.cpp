#include "hf.h"

HF::HF(){
	debug = false;
} /* default constructor */

void HF::molecule(const Molecule &moll) {
	mol = moll;
	nrelec = 0;
	energy = 0;
	cntstep = 0;

	unsigned int cnt = 0; /* counter for orbitals */
	for(unsigned int i=0; i<mol.nratoms(); i++) { /* loop over atoms */
		nrelec += mol[i].nrelecs(); /* get total number of electrons */
		for(unsigned int j=0; j<mol[i].nrorbs(); j++) { /* loop over orbitals per atom */
			std::ostringstream oss;
			oss << "[" << i+1 << "] " << mol[i].ps() << "\t ("
			<< mol[i][j].orb() << ")";
			std::string str = oss.str();
			orblist.push_back(str);
			orbitals.push_back(mol[i][j]);
			cnt++;
		}
	}
	/* set number of orbitals and atoms */
	nrorbs = cnt;
	nrat = mol.nratoms();

	/* resize matrices */
	S.resize(nrorbs,nrorbs);
	H.resize(nrorbs,nrorbs);
	T.resize(nrorbs,nrorbs);
	V.resize(nrat);
	P.resize(nrorbs,nrorbs);
	Cc.resize(nrorbs,nrorbs);
	C.resize(nrorbs,nrorbs);
	X.resize(nrorbs,nrorbs);
	Xp.resize(nrorbs,nrorbs);
	G.assign(nrorbs,nrorbs,0.0);
	for(unsigned int i=0; i<V.size(); i++) {
		V[i].resize(nrorbs,nrorbs);
	}
	TE.resize(teindex(nrorbs,nrorbs,nrorbs,nrorbs)+1, -1.0);

	if(debug) {
		listorbs();
	}
}

void HF::setup() {

	/* populate all matrices */
	for(unsigned int i=0; i<nrorbs; i++) {
		for(unsigned int j=0; j<nrorbs; j++) {
			S[i][j] = cgf_overlap(orbitals[i],orbitals[j]);
			T[i][j] = cgf_kinetic(orbitals[i],orbitals[j]);
			H[i][j] = T[i][j];

			/* V matrices */
			for(unsigned int k=0; k<nrat; k++) {
				V[k][i][j] = cgf_nuclear(orbitals[i],orbitals[j],mol[k]);
				H[i][j] += V[k][i][j];
			}

			/* TE list */
			for(unsigned int k=0; k<nrorbs; k++) {
				for(unsigned int l=0; l<nrorbs; l++) {
					unsigned int index = teindex(i,j,k,l);
					if(TE[index] == -1.0) {
						TE[index] = cgf_repulsion(orbitals[i],orbitals[j],orbitals[k],orbitals[l]);
					}
				}
			}
		}
	}

	/* uncomment the lines below for debugging purposes */
	//std::cout << S;

	X = canorg(S);
	Xp = transpose(X);

	/* calculate nuclear repulsion energy */
	nucl_repul = calcnuclrepul();

	if(debug) {
		printT();
		printH();
		printV();
		printS();
		printX();
		printTE();
	}
}

void HF::listorbs() const {
	std::cout << "--- List of orbitals ---" << std::endl;
	for(unsigned int i = 0; i<orblist.size(); i++) {
		std::cout << orblist[i] << std::endl;
	}
}

void HF::printS() const {
	std::cout << "\t" << "--- Smatrix ---" << std::endl;
	std::cout << S;
}

void HF::printX() const {
	std::cout << "\t" << "--- Xmatrix ---" << std::endl;
	std::cout << X;
}

void HF::printFp() const {
	std::cout << "\t" << "--- F' matrix ---" << std::endl;
	std::cout << Fp;
}

void HF::printF() const {
	std::cout << "\t" << "--- F matrix ---" << std::endl;
	std::cout << F;
}

void HF::printG() const {
	std::cout << "\t" << "--- G matrix ---" << std::endl;
	std::cout << G;
}

void HF::printT() const {
	std::cout << "\t" << "--- Tmatrix ---" << std::endl;
	std::cout << T;
}

void HF::printH() const {
	std::cout << "\t" << "--- Hcore matrix ---" << std::endl;
	std::cout << H;
}

void HF::printV() const {
	for(unsigned int i=0; i<V.size(); i++) {
		std::cout << "\t" << "--- V(" << i+1 << ")matrix ---" << std::endl;
		std::cout << V[i];
	}
}

void HF::printTE() const {
	std::cout << "\t" << "--- two-electron matrix ---" << std::endl;
	for(unsigned int i=0; i<nrorbs; i++) {
		for(unsigned int j=0; j<nrorbs; j++) {
			for(unsigned int k=0; k<nrorbs; k++) {
				for(unsigned int l=0; l<nrorbs; l++) {
					std::cout << "(" << i+1 << "," << j+1
					<< "," << k+1 << "," << l+1 << ")"
					<< " = " << TE[teindex(i,j,k,l)] << std::endl;
				}
			}
		}
	}
}

void HF::step() {
cntstep++;

if(debug) {
	std::cout << "Start electronic step " << cntstep << std::endl;
}

unsigned int index1 = 0;
unsigned int index2 = 0;

	for(unsigned int i=0; i<nrorbs; i++) {
    for(unsigned int j=0; j<nrorbs; j++) {
			G[i][j] = 0; /* reset G matrix */
      for(unsigned int k=0; k<nrorbs; k++) {
        for(unsigned int l=0; l<nrorbs; l++) {
					index1 = teindex(i,j,k,l);
          index2 = teindex(i,l,k,j);
          G[i][j] += P[k][l] * (TE[index1] - 0.5 * TE[index2]);
        }
      }
    }
  }

	/* construct Fock Matrix and orthogonalize it */
	F = matsum(H,G);
	Fp = trimatprod(Xp,F,X);

	if(debug) {
		printH();
		printG();
		printF();
		printFp();
	}

	/* extract eigenvalues and eigenvectors */
	Symmeig eig(Fp,true);
	Cc = eig.z;

	/* calculate energy from orbitals */
	energy = calcen(eig);

	/* construct C and charge density matrices for new iterative round */
	C = matprod(X,Cc);
	P.assign(nrorbs, nrorbs, 0.0); /* reset P */
	for(unsigned int i=0; i<nrorbs; i++) {
		for(unsigned int j=0; j<nrorbs; j++) {
			for(unsigned int k=0; k<nrelec/2; k++) {
				P[i][j] += 2.0 * C[i][k] * C[j][k];
			}
		}
	}
}

void HF::run() {
	setup();
	iterate();
}

double HF::calcen(Symmeig &eig) {
	double energy = 0;

	MatDoub mat = matsum(H,F);
	for(unsigned int i=0; i<nrorbs; i++) {
		for(unsigned int j=0; j<nrorbs; j++) {
			energy += P[j][i]*mat[i][j];
		}
	}

	return energy * 0.5 + nucl_repul;
}

double HF::calcnuclrepul() {
	double repul = 0;
	for(unsigned int i=0; i<nrat; i++) {
		for(unsigned int j=i+1; j<nrat; j++) {
			repul += mol[i].nucl_chg() * mol[j].nucl_chg() / sqrt(dist2(mol[i].gr(), mol[j].gr() ) );
		}
	}
	return repul;
}

void HF::iterate() {
	double ediff = 1;
	double oldenergy = 1000; /* some random big number */
	unsigned int iter = 0;

	if(debug) {
		std::cout << "Start iteration routine..." << std::endl;
		std::cout << "--------------------------" << std::endl;
	}

	while(ediff > 1e-5) { /* loop until convergence criterion is met */
		iter++;
		step();
		std::cout << std::setprecision(10);
		std::cout << "Energy after iteration " << iter << ": " << energy << " Hartree" << std::endl;
		ediff = abs(energy - oldenergy);
		oldenergy = energy;
	}
}
