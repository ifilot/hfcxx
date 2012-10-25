#ifndef _VECTOR_H
#define _VECTOR_H

class Vector3{
	public:
	double x,y,z;

	public:
	Vector3(); /* default constructor */
	Vector3(const double xx, const double yy, const double zz);
	Vector3(const Vector3 &rhs);
};

#endif // _VECTOR_H
