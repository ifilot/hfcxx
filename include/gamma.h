/*
 * gamma.h
 *
 * evaluate incomplete gamma function 
 *
 * Author: Ivo Filot
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
