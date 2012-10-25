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
