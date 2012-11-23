#include "hf.h"

HF::HF(){} /* default constructor */

void HF::molecule(const Molecule &moll) {
	mol = moll;
	nrelec = 0;

	unsigned int cnt = 0; /* counter for orbitals */
	for(unsigned int i=0; i<mol.nratoms(); i++) { /* loop over atoms */
		nrelec += mol[i].nrelecs(); /* get total number of electrons */
		for(unsigned int j=0; j<mol[i].nrorbs(); j++) { /* loop over orbitals per atom */
			std::string str = "";
			str.append("(");
			str +=  i;
			str.append(mol[i].ps()).append(",").append(mol[i][j].orb()).append(")");
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
}

void HF::calc() {

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
	X = canorg(S);
	Xp = transpose(X);

	std::cout << S;
	std::cout << X;
	step();
	step();
	step();
	step();
}

void HF::listorbs() const {
	for(unsigned int i = 0; i<orblist.size(); i++) {
		std::cout << orblist[i] << std::endl;
	}
}

void HF::printS() const {
	std::cout << "\t" << "--- Smatrix ---" << std::endl;
	std::cout << S;

	Xmatrix X = canorg(S);
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
unsigned int index1 = 0;
unsigned int index2 = 0;

	for(unsigned int i=0; i<nrorbs; i++) {
    for(unsigned int j=0; j<nrorbs; j++) {
      for(unsigned int k=0; k<nrorbs; k++) {
        for(unsigned int l=0; l<nrorbs; l++) {
					index1 = teindex(i,j,k,l);
          index2 = teindex(i,l,k,j);
          G[i][j] += P[k][l] * (TE[index1] - 0.5 * TE[index2]);
        }
      }
    }
  }

	F = matsum(H,G);

	std::cout << "--- F matrix ---" << std::endl;
	std::cout << F;

	Fp = trimatprod(Xp,F,X);

	std::cout << "--- F' matrix ---" << std::endl;
	std::cout << Fp;

	Symmeig eig(Fp,true);
	Cc = eig.z;

	C = matprod(X,Cc);

	std::cout << "--- C matrix ---" << std::endl;
	std::cout << C;

	P.assign(nrorbs, nrorbs, 0.0); /* reset P */
	for(unsigned int i=0; i<nrorbs; i++) {
		for(unsigned int j=0; j<nrorbs; j++) {
			for(unsigned int k=0; k<nrelec/2; k++) {
				P[i][j] += 2.0 * C[i][k] * C[j][k];
			}
		}
	}
}
