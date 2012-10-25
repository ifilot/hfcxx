#ifndef _CGF_H
#define _CGF_H

#include<iostream>
#include<vector>
#include<string>
#include "vector.h"
#include "gto.h"

/* 
Gaussian Type Orbital

x^l * y^m * z^n * exp(-alpha * r^2)
*/

class CGF{
	public:
	double zeta;
	std::vector<GTO> gtos;
	Vector3 r;
	std::string type;

	public:
	CGF(const std::string type, const double zetaa, const Vector3 rr);
};

#endif //_CGF_H
