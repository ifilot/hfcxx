/*
 * func.cpp
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description:
 */

#include "func.h"

double sign(const double &a, const double &b) {
	return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a);
}

double sqr(const double x) {
	return x * x;
}

double min(const double &a, const double &b) {
	if(a > b) {
		return b;
	} else {
		return a;
	}
}

double max(const double &a, const double &b) {
	if(a < b) {
		return b;
	} else {
		return a;
	}
}

double abs(const double &x) {
	if(x < 0) {
		return -x;
	} else {
		return x;
	}
}

double binomial_prefactor(int s, int ia, int ib, double xpa, double xpb){
  int t;
  double sum=0.;
  for (t=0; t<s+1; t++)
    if ((s-ia <= t) && (t <= ib))
      sum += binomial(ia,s-t)*binomial(ib,t)*pow(xpa,ia-s+t)*pow(xpb,ib-t);
  return sum;
}

int binomial(int a, int b) {
	return fact(a)/(fact(b) * fact(a-b));
}

double dist2(const Vec3 &a, const Vec3 &b) {
	return pow(a.getx() - b.getx(),2.0) + 
		pow(a.gety() - b.gety(),2.0) + 
		pow(a.getz() - b.getz(),2.0);
}

Vec3 gaussian_product_center(const double &alpha1, const Vec3 &a, const double &alpha2, const Vec3 &b) {
	double gamma = alpha1 + alpha2;
	double x = (alpha1 * a.getx() + alpha2 * b.getx()) / gamma;
	double y = (alpha1 * a.gety() + alpha2 * b.gety()) / gamma;
	double z = (alpha1 * a.getz() + alpha2 * b.getz()) / gamma;

	return Vec3(x,y,z);
}

void swap(unsigned int &i, unsigned int &j) {
	unsigned int m = i;
	i = j;
	j = m;
}
