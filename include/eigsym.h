#ifndef _EIGSYM_H
#define _EIGSYM_H

#include "matrix.h"
#include "vector.h"
#include "eispack.h"
#include<cmath>

class Eigsym{
	public:
	Eigsym();
	Eigsym(const MatDoub &A, MatDoub &V, VecDoub &lambda);
	void eig(const MatDoub &A, MatDoub &V, VecDoub &lamda);
};

#endif //_EIGSYM_H
