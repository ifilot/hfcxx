#ifndef _FUNC_H
#define _FUNC_H

#include<cmath>
#include "vector.h"
#include "factorial.h"

/* min, max, abs functions */
double min(const double &a, const double &b);
double max(const double &a, const double &b);
double abs(double &x);

/* functions for binomial expansion */
double binomial_prefactor(const unsigned int &s, const unsigned int &m1, const unsigned int &m2, const double &x1, const double &x2);
double binomial(const unsigned int &a, const unsigned int &b);

/* functions for vectors */
double dist2(const Vector3 &a, const Vector3 &b);
Vector3 gaussian_product_center(const double &alpha1, const Vector3 &a, const double &alpha2, const Vector3 &b);

#endif //_FUNC_H
