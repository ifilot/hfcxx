/**************************************************************************
 *   canorg.cpp  --  This file is part of HFCXX.                          *
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
