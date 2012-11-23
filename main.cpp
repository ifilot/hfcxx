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
	Molecule H2;
	H2.addAtom("H",0,0,0);
	H2.addAtom("He",1.4,0,0);

	HF hf;
	hf.molecule(H2);
	hf.calc();

	return 0;
}
