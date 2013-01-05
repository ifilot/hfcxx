/*
 * vector.cpp
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description:
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

const double Vector3::getx() const {
	return x;
}

const double Vector3::gety() const {
	return y;
}

const double Vector3::getz() const {
	return z;
}
