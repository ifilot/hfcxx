/*
 * vec3.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: Special 3-element vector class used for describing points in R^3
 */
 
#ifndef _HFCXX_VEC3_H
#define _HFCXX_VEC3_H

#include<iostream>
#include<iomanip>
#include<vector>

class Vec3{
	private:
	double x,y,z;

	public:
	Vec3(); /* default constructor */
	Vec3(const double xx, const double yy, const double zz);
	Vec3(const Vec3 &rhs);

	const double getx() const;
	const double gety() const;
	const double getz() const;
};

/* typedefs */
typedef std::vector<double> VecDoub;
typedef std::vector<int> VecInt;

#endif // _HFCXX_VEC3_HH
