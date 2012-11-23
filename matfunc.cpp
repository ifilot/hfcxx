#include "matfunc.h"

MatDoub matprod(MatDoub &a, MatDoub &b) {
	unsigned int n = a.nrows();
	unsigned int m = b.ncols();
	unsigned int r = a.ncols();

	MatDoub ans(n,m,0.0);

	for(unsigned int i=0; i<n; i++) {
		for(unsigned int j=0; j<m; j++) {
			for(unsigned int k=0; k<r; k++) {
				ans[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return ans;
}

MatDoub matsum(MatDoub &a, MatDoub &b) {
	unsigned int n = a.nrows();
  unsigned int m = a.ncols();
	MatDoub ans(n,m,0.0);

	for(unsigned int i=0; i<n; i++) {
    for(unsigned int j=0; j<m; j++) {
			ans[i][j] = a[i][j] + b[i][j];
		}
	}

	return ans;
}

MatDoub trimatprod(MatDoub &a, MatDoub &b, MatDoub &c) {
	MatDoub temp = matprod(b,c);
	MatDoub ans = matprod(a,temp);

	return ans;
}
