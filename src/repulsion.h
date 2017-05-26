/**************************************************************************
 *   repulsion.h  --  This file is part of HFCXX.                         *
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

#ifndef _REPULSION_H
#define _REPULSION_H

#include <vector>

#include "config.h"
#include "gamma.h"
#include "func.h"
#include "vec3.h"
#include "gto.h"
#include "cgf.h"

double cgf_repulsion(const CGF &cgf1, const CGF &cgf2, const CGF &cgf3, const CGF &cgf4);
double gto_repulsion(const GTO &gto1, const GTO &gto2, const GTO &gto3, const GTO &gto4);

double coulomb_repulsion(const Vec3 &a, const double &norma, const int la, const int ma, const int na, const double &alphaa,
                         const Vec3 &b, const double &normb, const int lb, const int mb, const int nb, const double &alphab,
                         const Vec3 &c, const double &normc, const int lc, const int mc, const int nc, const double &alphac,
                         const Vec3 &d, const double &normd, const int ld, const int md, const int nd, const double &alphad);

std::vector<double> B_array(const int l1,const int l2,const int l3,const int l4,
        const double &p, const double &a, const double &b, const double &q, const double &c, const double &d,
        const double g1, const double g2, const double delta);

double B_term(const int i1, const int i2, const int r1, const int r2, const int u, const int l1, const int l2, const int l3, const int l4,
const double &px, const double &ax, const double &bx, const double &qx, const double &cx, const double &dx, const double &gamma1,
const double &gamma2, const double &delta);

double fB(const int i, const int l1, const int l2, const double &p, const double &a, const double &b, const int r, const double &q);
double B0(int i, int r, double q);
double fact_ratio2(const int a, const int b);

const unsigned int teindex(unsigned int i, unsigned int j, unsigned int k, unsigned int l);

#endif //_REPULSION_H
