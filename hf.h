#ifndef _HF_H
#define _HF_H

#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<sstream>
#include "molecule.h"
#include "clock.h"
#include "matrix.h"
#include "canorg.h"
#include "kinetic.h"
#include "overlap.h"
#include "nuclear.h"
#include "repulsion.h"

class HF{
	private:
	Molecule mol;
	unsigned int nrorbs;
	unsigned int nrat;
	unsigned int nrelec;
	unsigned int cntstep;
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

	public:
	bool debug; /* set debug to either true or false */
	HF(); /* default constructor */
	void molecule(const Molecule &moll);
	void listorbs() const;
	void run();

	/* iterative step functions */
	private:
	void step();
	void setup();
	void iterate();

	/* energy functions */
	double calcen(Symmeig &eig);
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
