/*
 * func.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: Series of small functions used extensively throughout the program
 */

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
