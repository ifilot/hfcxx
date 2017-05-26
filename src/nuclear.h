/**************************************************************************
 *   nuclear.h  --  This file is part of HFCXX.                           *
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
 
#ifndef _NUCLEAR_H
#define _NUCLEAR_H

#include<vector>
#include<cmath>
#include "gamma.h"
#include "func.h"
#include "vec3.h"
#include "cgf.h"
#include "atom.h"

double cgf_nuclear(CGF &cgf1, CGF &cgf2, const Atom &a);
double gto_nuclear(GTO &gto1, GTO &gto2, const Vec3 &c);
double nuclear(const Vec3 a, double norm1, int l1, int m1, int n1, double alpha1, const Vec3 b, double norm2, int l2, int m2, int n2, double alpha2, const Vec3 c);
std::vector<double> A_array(const int l1, const int l2, const double pa, const double pb, const double cp, const double g);
double A_term(const int i, const int r, const int u, const int l1, const int l2, const double pax, const double pbx, const double cpx, const double gamma);

#endif //_NUCLEAR_H
