#include<iostream>
#include "../vector.h"
#include "../cgf.h"
#include "../overlap.h"

int main() {

	CGF psi1("1s",1,Vector3(0,0,0));
	CGF psi2("1s",1,Vector3(1,0,0));
	CGF psi3("1s",8,Vector3(0,0,0)); // O
	CGF psi4("2s",8,Vector3(0,0,0)); // O
	CGF psi5("2px",8,Vector3(0,0,0)); // O
	CGF psi6("2py",8,Vector3(0,0,0)); // O

	std::cout << "Int <1sH|1sH>: ";
	std::cout << cgf_overlap(psi1,psi1) << std::endl;
	std::cout << "Int <1sH|1sH'>: ";
	std::cout << cgf_overlap(psi1,psi2) << std::endl;
	std::cout << "Int <1sO|1sO>: ";
	std::cout << cgf_overlap(psi3,psi3) << std::endl;
	std::cout << "Int <2sO|2sO>: ";
	std::cout << cgf_overlap(psi4,psi4) << std::endl;
	std::cout << "Int <1sO|2sO>: ";
	std::cout << cgf_overlap(psi3,psi4) << std::endl;
	std::cout << "Int <2sO|1sO>: ";
	std::cout << cgf_overlap(psi4,psi3) << std::endl;
	std::cout << "Int <2sO|2pxO>: ";
	std::cout << cgf_overlap(psi4,psi5) << std::endl;
	std::cout << "Int <2pxO|2pxO>: ";
	std::cout << cgf_overlap(psi5,psi5) << std::endl;
	std::cout << "Int <2pxO|2pyO>: ";
	std::cout << cgf_overlap(psi5,psi6) << std::endl;

	return 0;
}
