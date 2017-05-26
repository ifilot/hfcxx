/**************************************************************************
 *   gto.cpp  --  This file is part of HFCXX.                             *
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

#include "gto.h"

GTO::GTO(const double cc, const Vec3 rr, const double alphaa, const unsigned int ll, const unsigned int mm, const unsigned int nn) {
    r = rr;
    alpha = alphaa;
    l = ll;
    m = mm;
    n = nn;

    x = r.getx();
    y = r.gety();
    z = r.getz();

    c = cc;
    norm = calcnorm();
}

double GTO::calcnorm() const {
    const double pi = 3.14159265359;
    double nom = pow(2.0, 2.0*(l+m+n)+3.0/2.0)*pow(alpha,(l+m+n)+3.0/2.0);
    double denom = fact2(2*l-1)*fact2(2*m-1)*fact2(2*n-1)*pow(pi,3.0/2.0);

    return sqrt(nom / denom);
}

std::ostream& operator <<(std::ostream &os,const GTO &rhs) {
    os << std::setw(10) << std::setiosflags(std::ios::right);
    os << std::setprecision(10) << std::setiosflags(std::ios::fixed);
    os << "c = " << rhs.c << "\t" << "alpha = " << rhs.alpha << "\t" << "(l,m,n) = " << "("
         << rhs.l << "," << rhs.m << "," << rhs.n << ")";

    return os;
}
