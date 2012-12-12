#include "eigsym.h"

Eigsym::Eigsym(){}; /* default constructor */

Eigsym::Eigsym(const MatDoub &A, MatDoub &V, VecDoub &lambda) {
	eig(A,V,lambda);
}

void Eigsym::eig(const MatDoub &A, MatDoub &V, VecDoub &lambda) {
	unsigned int n = A.ncols();	/* size of the matrix */
	double a[n*n]; 	/* store initial matrix */
	double w[n];		/* store eigenvalues */
	int matz = 1;		/* return both eigenvalues as well as eigenvectors */
	double x[n*n]; 	/* store eigenvectors */

	for(unsigned int i=0; i<n; i++) {
		for(unsigned int j=0; j<n; j++) {
			a[i*n+j] = A[i][j];
		}
	}

	unsigned int ierr = 0;

	ierr = rs ( n, a, w, matz, x );

	V.assign(n,n,0.0);
	lambda.resize(n);
	for(unsigned int i=0; i<n; i++) {
		lambda[i] = w[i];
		for(unsigned int j=0; j<n; j++) {
			V[j][i] = x[i*n+j];
		}
	}
}
