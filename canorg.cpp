/*
 * canorg.cpp
 *
 * routine for canonical orthogonalization of overlap matrix (S)
 *
 */

#include "canorg.h"

Xmatrix canorg(const Smatrix &S) {
	unsigned int size = S.nrows();
	MatDoub mat(S);
	MatDoub U;
	VecDoub l;

	//Symmeig eig(mat,true);
	Eigsym es(mat,U,l);

	MatDoub D(size, size, 0.0); /* create diagonal matrix */
	/* populate diagonal matrix */
	for(unsigned int i=0; i<size; i++) {
		D[i][i] = 1.0 / sqrt(l[i]);
	}
	/* obtain inverse of u */
	MatDoub Uinv = transpose(U);

	MatDoub temp = matprod(D,Uinv);
	Xmatrix X = matprod(U,temp);

	return X;
}

MatDoub transpose(MatDoub &a) {
	MatDoub ans(a.ncols(), a.nrows() );

	for(unsigned int i=0;i<a.nrows();i++) {
		for(unsigned int j=0; j<a.ncols(); j++) {
			ans[j][i] = a[i][j];
		}
	}

	return ans;
}
