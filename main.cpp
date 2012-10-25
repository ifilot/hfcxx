#include<iostream>
#include "atom.h"
#include "cgf.h"
#include "factorial.h"
#include "overlap.h"

int main() {

	CGF psi1("1s",1.24,Vector3(0,0,0));
	CGF psi2("1s",1.24,Vector3(1,1,1));

	std::cout << cgf_overlap(psi1,psi2) << std::endl;

	return 0;
}
