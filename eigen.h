#ifndef _EIGEN_H
#define _EIGEN_H

#include<cmath>
#include <limits>
#include "func.h"
#include "vector.h"
#include "matrix.h"

void eigsrt(VecDoub, MatDoub);

struct Symmeig {
	int n;
	MatDoub z;
	VecDoub d;
	VecDoub e;
	bool yesvecs;

	Symmeig(MatDoub &a, bool yesvec);
	Symmeig(VecDoub &dd, VecDoub &ee, bool yesvec);
	void sort();
	void tred2();
	void tqli();
	double pythag(const double a, const double b);
};

#endif //_EIGEN_H
