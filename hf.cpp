#include "hf.h"

HF::HF(){} /* default constructor */

void HF::molecule(const Molecule &moll) {
	mol = moll;

	unsigned int cnt = 0; /* counter for orbitals */
	for(unsigned int i=0; i<mol.nratoms(); i++) { /* loop over atoms */
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

			/* V matrices */
			for(unsigned int k=0; k<nrat; k++) {
				V[k][i][j] = cgf_nuclear(orbitals[i],orbitals[j],mol[k]);
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

}

void HF::listorbs() const {
	for(unsigned int i = 0; i<orblist.size(); i++) {
		std::cout << orblist[i] << std::endl;
	}
}

void HF::printS() const {
	std::cout << "\t" << "--- Smatrix ---" << std::endl;
	std::cout << S;
}

void HF::printT() const {
	std::cout << "\t" << "--- Tmatrix ---" << std::endl;
	std::cout << T;
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
