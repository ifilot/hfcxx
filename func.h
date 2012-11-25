#ifndef _FUNC_H
#define _FUNC_H

#include<cmath>
#include "vector.h"
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
double dist2(const Vector3 &a, const Vector3 &b);
Vector3 gaussian_product_center(const double &alpha1, const Vector3 &a, const double &alpha2, const Vector3 &b);

/* swap functions */
void swap(unsigned int &i, unsigned int &j);

#endif //_FUNC_H
