#ifndef _HF_H
#define _HF_H

#include<vector>
#include "atom.h"
#include "matrix.h"


class HF{
	private:
	std::vector<Atom> atoms;
	Hmatrix H; /* hamiltonian matrix */
	Smatrix S; /* overlap matrix */

	public:
	HF(); /* default constructor */
	void setAtoms(const std::vector<Atom> &atomsin);
};

#endif //_HF_H
