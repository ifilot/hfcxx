#ifndef _OUTPUT_H
#define _OUTPUT_H

#include<iostream>
#include<sstream>
#include "version.h"
#include "molecule.h"

class Output{
	private:
	std::string spacer;

	public:
	Output();
	void printVersion();
	void printGeometry(Molecule &mol);
	void printFinal(unsigned int iter, double en, unsigned int nrat);
	void printEnd(double time);
};

#endif //_OUTPUT_H
