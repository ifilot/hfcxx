/**************************************************************************
 *   gto.h  --  This file is part of HFCXX.                               *
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

#ifndef _GTO_H
#define _GTO_H

#include<cmath>
#include<iostream>
#include "vec3.h"
#include "factorial.h"

/*
Gaussian Type Orbital

x^l * y^m * z^n * exp(-alpha * r^2)
*/

class GTO{
    public:
    double c;   /* coefficient */
    unsigned int l,m,n; /* powers */
    double x,y,z;   /* positions */
    double alpha;   /* alpha value in the exponent */
    Vec3 r; /* position vector */
    double norm;

    public:
    GTO(const double c, const Vec3 rr, const double alphaa, const unsigned int ll, const unsigned int mm, const unsigned int nn);
    friend std::ostream& operator <<(std::ostream &os,const GTO &rhs);

    private:
    double calcnorm() const;
};

#endif //_GTO_H
