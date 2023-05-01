/**************************************************************************
 *   hf.h  --  This file is part of HFCXX.                                *
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

#ifndef _HF_H
#define _HF_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <array>
#include <string>
#include <sstream>

#include "config.h"
#include "molecule.h"
#include "clock.h"
#include "matrix.h"
#include "canorg.h"
#include "kinetic.h"
#include "overlap.h"
#include "nuclear.h"
#include "repulsion.h"
#include "eigsym.h"
#include "output.h"

class HF{
    private:
    Molecule mol;
    unsigned int nrorbs;
    unsigned int nrat;
    unsigned int nrelec;
    unsigned int cntstep;
    unsigned int bss;
    Clock clock;
    std::vector<std::string> orblist;
    std::vector<CGF> orbitals;
    Hmatrix H; /* hamiltonian matrix */
    Smatrix S; /* overlap matrix */
    Tmatrix T; /* kinetic matrix */
    Pmatrix P; /* density matrix */
    Pmatrix Pnew; /* density matrix */
    Gmatrix G; /* P + TE matrix */
    Fmatrix F; /* Fock matrix */
    Fmatrix Fp; /* Fock matrix */
    Xmatrix X; /* X matrix */
    Xmatrix Xp; /* X matrix */
    Cmatrix C; /* Coefficient matrix */
    Ccmatrix Cc; /* Cprime matrix */
    std::vector<Vmatrix> V; /* set of nuclear attraction matrices */
    std::vector<double> TE; /* set of double electron integrals */
    std::vector<double> energies; /* set of energies of each iterative step */
    std::vector<double> itertimes; /* set of iteration times */
    std::vector<double> molorben; /* energy of molecular orbitals */
    double energy; /* current energy in the iterative loop */
    double nucl_repul; /* nuclear repulsion energy */
    double alpha; /* damping parameter for the iterative SCF cycles */
    Output out;

    public:
    bool debug; /* set debug to either true or false */
    HF(); /* default constructor */
    void molecule(const Molecule &moll);
    void listorbs() const;
    void run();

    inline double get_energy() const {
        return this->energy;
    }

    /* iterative step functions */
    private:
    void step();
    void setup();
    unsigned int iterate();

    /* energy functions */
    double calcen();
    double calcnuclrepul();

    /* special output functions for debugging purposes */
    public:
    void printS() const;
    void printX() const;
    void printT() const;
    void printG() const;
    void printF() const;
    void printFp() const;
    void printH() const;
    void printV() const;
    void printTE() const;
    void molorbs() const;
};

#endif //_HF_H
