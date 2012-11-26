#include<iostream>
#include <iomanip>
#include "hf.h"
#include "version.h"
#include "clock.h"

int main() {

	/* output compile information on execution */
	version();

	/* keep track of the time */
	Clock clock;

	/* define molecule */
	Molecule H2O;
	H2O.addAtom("C",0,0,0);
	H2O.addAtom("H",1,0,0);
	H2O.addAtom("H",0,1,0);
	//H2O.addAtom("O",0,0,2);
	//H2O.addAtom("H",1,0,2);
	//H2O.addAtom("H",0,1,2);
	//H2O.addAtom("O",0,0,4);
	//H2O.addAtom("H",1,0,4);
	//H2O.addAtom("H",0,1,4);
	//H2O.addAtom("O",0,0,6);
	//H2O.addAtom("H",1,0,6);
	//H2O.addAtom("H",0,1,6);

	HF hf;
	hf.debug = true;
	hf.molecule(H2O);
	hf.run();

	clock.toc();
	std::cout << "Execution time: " << clock.passed() << " ms" << std::endl;

	return 0;
}
