/**************************************************************************
 *   gamma.h  --  This file is part of HFCXX.                             *
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
 
/*
 *
 * References:
 * [1] Numerical Recipes
 * William H. Press, Saul A. Teukolsky, William T., 
 * Vetterling and Brian P. Flannery
 * 3rd edition page 261
 * ISBN-13: 978-0521880688
 *
 * The functions below have all been obtained using ref [1]
 */

#ifndef _GAMMA_H
#define _GAMMA_H

#include<iostream>
#include <limits>
#include "func.h"

double Fgamma(const double m, double x);
double gamm_inc(const double a, const double x);
double gammp(const double m, const double x);
double gser(const double a, const double x);
double gammln(const double xx);
double gcf(const double a, const double x);
double gammpapprox(double a, double x, int psig);

#endif
