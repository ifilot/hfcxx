/**************************************************************************
 *   hf.cpp  --  This file is part of HFCXX.                              *
 *                                                                        *
 *   Copyright (C) 2012, Ivo Filot                                        *
 *                                                                        *
 *   HFCXX is free software:                                              *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   HFCXX is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/

#include "hf.h"

HF::HF(){
    debug = false;
    alpha = 0.5;
    bss = 0;
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
            cnt++;
            bss += mol[i][j].gtos.size();
            std::ostringstream oss;
            oss << "[" << cnt << "] " << mol[i].ps()
            <<  i+1 << "\t ("   << mol[i][j].orb() << ")";
            std::string str = oss.str();
            orblist.push_back(str);
            orbitals.push_back(mol[i][j]);
        }
    }
    /* set number of orbitals and atoms */
    nrorbs = cnt;
    nrat = mol.nratoms();

    /* resize matrices */
    S.assign(nrorbs,nrorbs, 0.0);
    H.assign(nrorbs,nrorbs, 0.0);
    T.assign(nrorbs,nrorbs, 0.0);
    V.resize(nrat);
    P.assign(nrorbs,nrorbs, 0.0);
    Cc.assign(nrorbs,nrorbs, 0.0);
    C.assign(nrorbs,nrorbs, 0.0);
    X.assign(nrorbs,nrorbs, 0.0);
    Xp.assign(nrorbs,nrorbs, 0.0);
    G.assign(nrorbs,nrorbs,0.0);
    for(unsigned int i=0; i<V.size(); i++) {
        V[i].resize(nrorbs,nrorbs);
    }
    TE.resize(teindex(nrorbs,nrorbs,nrorbs,nrorbs)+1, -1.0);

    if(debug) {
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "          LIST INPUT           " << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << std::endl;
        listorbs();
    }
}

void HF::setup() {

    if(debug) {
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "             OUTPUT            " << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << std::endl;
    }

    if(debug) {
        clock.tic();
        std::cout << "Constructing S matrix...";
    }

    /* populate all matrices */
    for(unsigned int i=0; i<nrorbs; i++) {
        for(unsigned int j=0; j<nrorbs; j++) {
            S[i][j] = cgf_overlap(orbitals[i],orbitals[j]);
        }
    }

    if(debug) {
        clock.toc();
        std::cout << " done [ " << clock.passed() << " ms ]" << std::endl;
    }

    if(debug) {
        clock.tic();
        std::cout << "Constructing T matrix...";
    }

    for(unsigned int i=0; i<nrorbs; i++) {
        for(unsigned int j=0; j<nrorbs; j++) {
            T[i][j] = cgf_kinetic(orbitals[i],orbitals[j]);
            H[i][j] = T[i][j];
        }
    }

    if(debug) {
        clock.toc();
        std::cout << " done [ " << clock.passed() << " ms ]" << std::endl;
    }

    if(debug) {
        clock.tic();
        std::cout << "Constructing V matrices...";
    }

    /* V matrices */
    for(unsigned int i=0; i<nrorbs; i++) {
        for(unsigned int j=0; j<nrorbs; j++) {
            for(unsigned int k=0; k<nrat; k++) {
                V[k][i][j] = cgf_nuclear(orbitals[i],orbitals[j],mol[k]);
                H[i][j] += V[k][i][j];
            }
        }
    }

    if(debug) {
        clock.toc();
        std::cout << " done [ " << clock.passed() << " ms ]" << std::endl;
    }

    if(debug) {
        clock.tic();
        std::cout << "Constructing TE matrix... (" << teindex(nrorbs-1,nrorbs-1,nrorbs-1,nrorbs-1)+1 << ") " << std::endl;
    }

    /* TE list */
    double tecnt=0;
    for(unsigned int i=0; i<nrorbs; i++) {
        for(unsigned int j=0; j<=i; j++) {
            unsigned int ij = i*(i+1)/2 + j;
            for(unsigned int k=0; k<nrorbs; k++) {
                for(unsigned int l=0; l<=k; l++) {
                    unsigned int kl = k * (k+1)/2 + l;
                    if(ij <= kl) {
                        unsigned int index = teindex(i,j,k,l);
                        tecnt++;
                        TE[index] = cgf_repulsion(orbitals[i],orbitals[j],orbitals[k],orbitals[l]);
                    }
                }
            }
        }
    }

    if(debug) {
        clock.toc();
        std::cout << " done [ " << clock.passed() << " ms ] ";
        std::cout << tecnt << " (i,j|k,l) iterations" << std::endl;

        printS();
        //printTE();
    }

    X = canorg(S);
    Xp = transpose(X);

    if(debug) {
        printX();
    }

    /* calculate nuclear repulsion energy */
    nucl_repul = calcnuclrepul();
}

void HF::step() {
cntstep++;

unsigned int index1 = 0;
unsigned int index2 = 0;

    for(unsigned int i=0; i<nrorbs; i++) {
    for(unsigned int j=0; j<nrorbs; j++) {
            G[i][j] = 0.; /* reset G matrix */
      for(unsigned int k=0; k<nrorbs; k++) {
        for(unsigned int l=0; l<nrorbs; l++) {
                    index1 = teindex(i,j,l,k);
          index2 = teindex(i,k,l,j);
          G[i][j] += P[k][l] * (TE[index1] - 0.5 * TE[index2]);
        }
      }
    }
  }

    /* construct Fock Matrix and orthogonalize it */
    F = matsum(H,G);
    Fp = trimatprod(Xp,F,X);

    /* extract eigenvalues and eigenvectors */
    Eigsym es(Fp,Cc,molorben);

    /* calculate energy from orbitals */
    energy = calcen();
    //molorben = eig.d;

    /* construct C and charge density matrices for new iterative round */
    C = matprod(X,Cc);
    Pnew.assign(nrorbs, nrorbs, 0.0); /* reset P */
    for(unsigned int i=0; i<nrorbs; i++) {
        for(unsigned int j=0; j<nrorbs; j++) {
            for(unsigned int k=0; k<nrelec/2; k++) {
                Pnew[i][j] += 2.0 * C[i][k] * C[j][k];
            }
        }
    }


    /*  the new density matrix P is made by using a damping technique.
            see for instance: Schlegel et. all, Comput. Adv. Org. Chem.,
            Molecular Structure and Reactivity, (1991), 167-185 */
    for(unsigned int i=0; i<nrorbs; i++) {
        for(unsigned int j=0; j<nrorbs; j++) {
            P[i][j] = (1.0-alpha) * Pnew[i][j] + alpha * P[i][j];
        }
    }
}

void HF::run() {
    setup();
    unsigned int iter = iterate();
    out.print_orbitals(molorben, orblist, C, nrelec);
    out.print_summary(iter,energy,nrat,orblist.size(), bss);
}

double HF::calcen() {
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

unsigned int HF::iterate() {
    double ediff = 1;
    double oldenergy = 1000; /* some random big number */
    unsigned int iter = 0;
    double passed = 0;

    if(debug) {
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Start electronic convergence..." << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }

    while(ediff > 1e-9) { /* loop until convergence criterion is met */
        /* start clock */
        clock.tic();

        iter++;
        step();
        std::cout << std::setprecision(10);
        ediff = abs(energy - oldenergy);
        oldenergy = energy;
        energies.push_back(energy);

        /* save iteration time */
        clock.toc();
        passed = clock.passed();
        itertimes.push_back(passed);

        /* output result to commandline */
        if(debug) {
            std::cout << "Energy after iteration " << iter << ":\t " << energy << " Hartree\t"
            << " [ " << passed << " ms ] " << std::endl;
        }

        if(iter > 100) {
            std::cout << "Too may iteration steps.. terminating and outputting results." << std::endl;
            break;
        }
    }

    if(debug) {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "End electronic convergence...  " << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }

    /* output resulting orbitals */
    if(debug) {
        molorbs();
    }

    return iter;
}

void HF::molorbs() const {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "      Molecular orbitals       " << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << std::endl;
    for(unsigned int i=0; i<nrorbs; i++) {
        std::cout << "*** " << i+1 << "\t" << molorben[i] << " HT" << " --- (";
        if(i < nrelec / 2) {
            std::cout << " Occupied ) ***" << std::endl;
        } else {
            std::cout << " Virtual ) ***" << std::endl;
        }

        /* output occupancies */
        for(unsigned int j=0; j<nrorbs; j++) {
            std::cout.setf(std::ios::fixed);
            std::cout << orblist[j] << "\t\t" << std::setprecision(4)
            << C[j][i] << std::endl; /* note that the eigenvectors are column vectors */
        }
        std::cout << "--------------------" << "\t" << "------" << std::endl;

        std::cout << std::endl;
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
