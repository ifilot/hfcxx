#include<iostream>
#include <iomanip>
#include "hf.h"
#include "factorial.h"
#include "overlap.h"
#include "kinetic.h"
#include "gamma.h"
#include "nuclear.h"
#include "repulsion.h"
#include "matrix.h"
#include "ludcmp.h"

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
