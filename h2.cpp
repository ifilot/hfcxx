#include<iostream>
#include <iomanip>
#include "atom.h"
#include "cgf.h"
#include "factorial.h"
#include "overlap.h"
#include "kinetic.h"
#include "gamma.h"
#include "nuclear.h"
#include "repulsion.h"

int main() {

	/* define atoms */
	Atom h1(1,0,0,0);
	Atom h2(1,1.4,0,0);

	/* define wavefunctions */
	CGF psi1("1s",1.24,Vector3(0,0,0));
	CGF psi2("1s",1.24,Vector3(1.4,0,0));

	/* overlap integrals */
	std::cout << "\t" << "----S----" << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_overlap(psi1,psi1) << "\t" << cgf_overlap(psi1,psi2) << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_overlap(psi2,psi1) << "\t" << cgf_overlap(psi2,psi2) << std::endl;

	/* kinetic integrals */
	std::cout << "\t"  << "----T----" << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_kinetic(psi1,psi1) << "\t" << cgf_kinetic(psi1,psi2) << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_kinetic(psi2,psi1) << "\t" << cgf_kinetic(psi2,psi2) << std::endl;

	/* nuclear attraction integrals */
	std::cout << "\t"  << "----V(1)----" << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_nuclear(psi1,psi1,h1) << "\t" << cgf_nuclear(psi1,psi2,h1) << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_nuclear(psi2,psi1,h1) << "\t" << cgf_nuclear(psi2,psi2,h1) << std::endl;

	std::cout << "\t"  << "----V(2)----" << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_nuclear(psi1,psi1,h2) << "\t" << cgf_nuclear(psi1,psi2,h2) << std::endl;
	std::cout << std::setw(10) << std::setprecision(5) << cgf_nuclear(psi2,psi1,h2) << "\t" << cgf_nuclear(psi2,psi2,h2) << std::endl;

	/* two-electron repulsion integrals */
	std::cout << "\t"  << "----TE----" << std::endl;
	std::cout << "(1,1,1,1)" << "\t"  << cgf_repulsion(psi1, psi1, psi1, psi1) << std::endl;
	std::cout << "(1,1,2,2)" << "\t"  << cgf_repulsion(psi1, psi1, psi2, psi2) << std::endl;
	std::cout << "(2,1,1,1)" << "\t"  << cgf_repulsion(psi2, psi1, psi1, psi1) << std::endl;
	std::cout << "(2,1,2,1)" << "\t"  << cgf_repulsion(psi2, psi1, psi2, psi1) << std::endl;

	return 0;
}
