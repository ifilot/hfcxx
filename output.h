#ifndef _OUTPUT_H
#define _OUTPUT_H

#include<iostream>
#include<sstream>
#include<vector>
#include "version.h"
#include "molecule.h"
#include "matrix.h"

class Output{
	private:
	std::string spacer;

	public:
	Output();
	void printVersion();
	void printGeometry(Molecule &mol);
	void printFinal(unsigned int iter, double en, unsigned int nrat, unsigned int nrorbs);
	void printEnd(double time);
	void printOrbitals(const std::vector<double> &molorben, const std::vector<std::string> &orblist, const MatDoub &C, unsigned int nrelec);
};

#endif //_OUTPUT_H
