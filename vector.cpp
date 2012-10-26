/*
 *	vector.cpp
 *
 *	Author: Ivo Filot
 *	Modified: 2012-08-30
 *
 *	Note because below are implementations of template member functions, this file
 *  is included in vector.h. In principle, the pre-compiler merges this file
 *  together with the header file, but for convenience, the declaration and
 *  implementation are seperated (although for the compiler not).
 */

#include "vector.h"

Vector3::Vector3() { /* default constructor */
	x = y = z =0;
}

Vector3::Vector3(const double xx, const double yy, const double zz) {
	x = xx;
	y = yy;
	z = zz;
}

Vector3::Vector3(const Vector3 &rhs) {
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}
