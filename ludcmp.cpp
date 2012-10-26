/*
 *	ludcmp.cpp
 *
 *	Author: Ivo Filot
 *	Modified: 2012-08-30
 *
 */

#include "ludcmp.h"

LUdcmp::LUdcmp(MatDoub &a):
n(a.nrows()), lu(a), indx(n), aref(a) {
	const double TINY=1.0e-40; //a really tiny number
	unsigned int imax;
	double big,temp;
	VecDoub vv(n);	//stores the implicit scaling of each row
	d=1.0;					//no row interchanges yet

	for(unsigned int i=0; i<n; i++) {
		big = 0.0;
		for(unsigned int j=0; j<n; j++) {
			if((temp = abs(lu[i][j])) > big ) {
				big = temp;
			}
		}
		if(big == 0.0) {
			throw("Singular matrix in LUdcmp");
		}
		vv[i] = 1.0 / big; //save the scaling
	}

	for(unsigned int k=0; k<n; k++) {
		big = 0.0;
		imax = k;
		for(unsigned int i=k; i<n; i++) {
			temp = vv[i] * abs(lu[i][k]);
			if(temp > big) {
				big = temp;
				imax = i;
			}
		}
		if(k != imax) {
			/* 	alternative method instead of rowswap, leave this here for
					debugging purposes. */
			/*
			for(int j=0; j<n; j++) {
				temp = lu[imax][j];
				lu[imax][j] = lu[k][j];
				lu[k][j] = temp;
			}
			*/
			lu.rowswap(imax,k);
			d = -d;							//change parity
			vv[imax] = vv[k];
		}
		indx[k] = imax;

		if(lu[k][k] == 0.0) {
			lu[k][k] = TINY;
		}

		for(unsigned int i=k+1; i<n; i++) {
			temp = lu[i][k] /= lu[k][k];	//divide by the pivot element
			for(unsigned int j=k+1; j<n; j++) {
				lu[i][j] -= temp * lu[k][j];
			}
		}
	}
}

void LUdcmp::solve(VecDoub &b, VecDoub &x) {
	unsigned int i;
	unsigned int ii=0,j,ip;	//note: because i,j are used outside for-loops, they
													//have to be defined in advance
	double sum;

	if(b.size() != n || x.size() != n) {
		throw("LUdcmp::solve bad sizes");
	}

	for(i=0; i<n; i++) {
		x[i] = b[i];
	}

	for(i=0; i<n; i++) {
		ip=indx[i];
		sum = x[ip];
		x[ip] = x[i];
		if(ii != 0) {
			for(j=ii-1; j<i; j++) {
				sum -= lu[i][j] * x[j];
			}
		} else {
			if(sum != 0.0) {
				ii = i+1;
			}
		}
		x[i] = sum;
	}

	for(int i=n-1; i>=0; i--) {
		sum = x[i];
		for(j=i+1; j<n; j++) {
			sum -= lu[i][j] * x[j];
		}
		x[i] = sum / lu[i][i];
	}
}

void LUdcmp::solve(MatDoub &b, MatDoub &x) {
	unsigned int i,j,m=b.ncols();

	if(b.nrows() !=n || x.nrows() !=n || b.ncols() != x.ncols()) {
		throw("LUdcmp::solve bad sizes");
	}

	VecDoub xx(n);
	for(j=0; j<m; j++) {
		for(i=0; i<n; i++) {
			xx[i] = b[i][j];
		}

		solve(xx,xx);

		for(i=0; i<n; i++) {
			x[i][j] = xx[i];
		}
	}
}

double LUdcmp::det() {
	double dd = d;
	for(unsigned int i=0; i<n; i++) {
		dd *= lu[i][i];
	}
	return dd;
}

MatDoub LUdcmp::lud() {
	return lu;
}

void LUdcmp::inverse(MatDoub &ainv) {
	unsigned int i,j;
	ainv.resize(n,n);

	/* set matrix ainv to unity */
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			ainv[i][j] = 0.;
		}
		ainv[i][i] = 1.;
	}

	solve(ainv,ainv);
}
