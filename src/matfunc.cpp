/**************************************************************************
 *   matfunc.cpp  --  This file is part of HFCXX.                         *
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
