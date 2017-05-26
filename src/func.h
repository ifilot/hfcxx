/**************************************************************************
 *   func.h  --  This file is part of HFCXX.                              *
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

#ifndef _FUNC_H
#define _FUNC_H

#include<cmath>
#include "vec3.h"
#include "factorial.h"

/* sign and square */
double sign(const double &a, const double &b);
double sqr(const double x);

/* min, max, abs functions */
double min(const double &a, const double &b);
double max(const double &a, const double &b);
double abs(const double &x);

/* functions for binomial expansion */
double binomial_prefactor(int s, int m1, int m2, double x1, double x2);
int binomial(int a, int b);

/* functions for vectors */
double dist2(const Vec3 &a, const Vec3 &b);
Vec3 gaussian_product_center(const double &alpha1, const Vec3 &a, 
  const double &alpha2, const Vec3 &b);

/* swap functions */
void swap(unsigned int &i, unsigned int &j);

#endif //_FUNC_H
