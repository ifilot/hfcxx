/**************************************************************************
 *   overlap.h  --  This file is part of HFCXX.                           *
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

#ifndef _OVERLAP_H
#define _OVERLAP_H

#include "gto.h"
#include "cgf.h"
#include "func.h"

double cgf_overlap(CGF &cgf1, CGF &cgf2);
double gto_overlap(GTO &gto1, GTO &gto2);
double overlap(double alpha1, int l1, int m1, int n1, Vec3 &a,
double alpha2, int l2, int m2, int n2, Vec3 &b);
double overlap_1D(int l1, int l2, double x1, double x2, double gamma);

#endif //_OVERLAP_H
