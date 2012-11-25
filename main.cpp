#include<iostream>
#include <iomanip>
#include "hf.h"

int main() {

	/* define molecule */
	Molecule H2O;
	H2O.addAtom("O",0,0,0);
	H2O.addAtom("H",1,0,0);
	H2O.addAtom("H",0,1,0);

	HF hf;
	hf.debug = true;
	hf.molecule(H2O);
	hf.run();

	return 0;
}
