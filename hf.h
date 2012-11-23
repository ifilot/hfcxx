#ifndef _HF_H
#define _HF_H

#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include "molecule.h"
#include "matrix.h"
#include "kinetic.h"
#include "overlap.h"
#include "nuclear.h"
#include "repulsion.h"

class HF{
	private:
	Molecule mol;
	unsigned int nrorbs;
	unsigned int nrat;
	std::vector<std::string> orblist;
	std::vector<CGF> orbitals;
	Hmatrix H; /* hamiltonian matrix */
	Smatrix S; /* overlap matrix */
	Tmatrix T; /* kinetic matrix */
	std::vector<Vmatrix> V; /* set of nuclear attraction matrices */
	std::vector<double> TE; /* set of double electron integrals */

	public:
	HF(); /* default constructor */
	void molecule(const Molecule &moll);
	void listorbs() const;
	void calc();

	/* special output functions for debugging purposes */
	void printS() const;
	void printT() const;
	void printV() const;
	void printTE() const;
};

#endif //_HF_H
