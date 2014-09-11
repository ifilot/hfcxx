/*
 * vector.cpp
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description:
 */

#include "vec3.h"

Vec3::Vec3() { /* default constructor */
	x = y = z =0;
}

Vec3::Vec3(const double xx, const double yy, const double zz) {
	x = xx;
	y = yy;
	z = zz;
}

Vec3::Vec3(const Vec3 &rhs) {
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

const double Vec3::getx() const {
	return x;
}

const double Vec3::gety() const {
	return y;
}

const double Vec3::getz() const {
	return z;
}
