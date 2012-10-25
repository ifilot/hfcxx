#include "func.h"

double binomial_prefactor(const unsigned int &s, const unsigned int &m1, const unsigned int &m2, const double &x1, const double &x2) {
	double sum = 0;

	for(unsigned i = 0; i <= s; i++) {
		if(s-m1 <= i && i <= m2) {
			sum += binomial(m1, s-i) * binomial(m2,i) *
				pow(x1,m1-s+i) * pow(x2,m2-i);
		}
	}

	return sum;
}

double binomial(const unsigned int &a, const unsigned int &b) {
	return fact(a)/fact(b)/fact(a-b);
}

double dist2(const Vector3 &a, const Vector3 &b) {
	return pow(a.x - b.x,2.0) + pow(a.y - b.y,2.0) + pow(a.z - b.z,2.0);
}

Vector3 gaussian_product_center(const double &alpha1, const Vector3 &a, const double &alpha2, const Vector3 &b) {
	double gamma = alpha1 + alpha2;
	double x = (alpha1 * a.x + alpha2 * b.x) / gamma;
	double y = (alpha1 * a.y + alpha2 * b.y) / gamma;
	double z = (alpha1 * a.z + alpha2 * b.z) / gamma;

	return Vector3(x,y,z);
}
