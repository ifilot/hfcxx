#include<iostream>
#include "atom.h"
#include "cgf.h"
#include "factorial.h"
#include "overlap.h"
#include "kinetic.h"
#include "gamma.h"
#include "nuclear.h"

int main() {

	Atom h(1,0,0,0);
	CGF psi1("1s",1.24,Vector3(0,0,0));
	CGF psi2("1s",1.24,Vector3(1.4,0,0));

	std::cout << cgf_nuclear(psi1,psi2,h) << std::endl;

	return 0;
}
