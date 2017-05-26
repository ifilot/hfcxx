/**************************************************************************
 *   eigsym.h  --  This file is part of HFCXX.                            *
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

#ifndef _EIGSYM_H
#define _EIGSYM_H

#include "matrix.h"
#include "vec3.h"
#include "eispack.h"
#include<cmath>

class Eigsym{
    public:
    Eigsym();
    Eigsym(const MatDoub &A, MatDoub &V, VecDoub &lambda);
    void eig(const MatDoub &A, MatDoub &V, VecDoub &lamda);
};

#endif //_EIGSYM_H
