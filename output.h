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
};

#endif //_OUTPUT_H
