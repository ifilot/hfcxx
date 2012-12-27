/*
 * nuclear.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: Nuclear attraction integrals
 */
 
#ifndef _NUCLEAR_H
#define _NUCLEAR_H

#include<vector>
#include<cmath>
#include "gamma.h"
#include "func.h"
#include "vector.h"
#include "cgf.h"
#include "atom.h"

double cgf_nuclear(CGF &cgf1, CGF &cgf2, const Atom &a);
double gto_nuclear(GTO &gto1, GTO &gto2, const Vector3 &c);
double nuclear(const Vector3 a, double norm1, int l1, int m1, int n1, double alpha1, const Vector3 b, double norm2, int l2, int m2, int n2, double alpha2, const Vector3 c);
std::vector<double> A_array(const int l1, const int l2, const double pa, const double pb, const double cp, const double g);
double A_term(const int i, const int r, const int u, const int l1, const int l2, const double pax, const double pbx, const double cpx, const double gamma);

#endif //_NUCLEAR_H
