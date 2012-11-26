#ifndef _GTO_H
#define _GTO_H

#include<cmath>
#include<iostream>
#include "vector.h"
#include "factorial.h"

/* 
Gaussian Type Orbital

x^l * y^m * z^n * exp(-alpha * r^2)
*/

class GTO{
	public:
	double c;	/* coefficient */
	unsigned int l,m,n; /* powers */
	double x,y,z;	/* positions */
	double alpha;	/* alpha value in the exponent */
	Vector3 r; /* position vector */

	public:
	GTO(const double c, const Vector3 &rr, const double alphaa, const unsigned int ll, const unsigned int mm, const unsigned int nn);
	double norm() const;

	friend std::ostream& operator <<(std::ostream &os,const GTO &rhs);
};

#endif //_GTO_H
