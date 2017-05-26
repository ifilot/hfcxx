/**************************************************************************
 *   eigsym.cpp  --  This file is part of HFCXX.                          *
 *                                                                        *
 *   Copyright (C) 2012, Ivo Filot                                        *
 *                                                                        *
 *   HFCXX is free software:                                              *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   HFCXX is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/

#include "eigsym.h"

Eigsym::Eigsym(){}; /* default constructor */

Eigsym::Eigsym(const MatDoub &A, MatDoub &V, VecDoub &lambda) {
    eig(A,V,lambda);
}

void Eigsym::eig(const MatDoub &A, MatDoub &V, VecDoub &lambda) {
    unsigned int n = A.ncols(); /* size of the matrix */
    double a[n*n];  /* store initial matrix */
    double w[n];        /* store eigenvalues */
    int matz = 1;       /* return both eigenvalues as well as eigenvectors */
    double x[n*n];  /* store eigenvectors */

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
