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
