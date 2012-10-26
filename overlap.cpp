#include "overlap.h"

double cgf_overlap(CGF &cgf1, CGF &cgf2) {
	const double pi = 3.14159265359;
	unsigned int i = cgf1.gtos.size();
	unsigned int j = cgf2.gtos.size();

	double sum = 0;
	double norm1, norm2;

	for(unsigned int k = 0; k < i; k++) {
		for(unsigned int l = 0; l < j; l++) {
			norm1 = pow(2.0 * cgf1.gtos[k].alpha / pi, 0.75);
			norm2 = pow(2.0 * cgf2.gtos[l].alpha / pi, 0.75);
			sum += cgf1.gtos[k].c * cgf2.gtos[l].c * norm1 * norm2 * gto_overlap(cgf1.gtos[k], cgf2.gtos[l]);
		}
	}

	return sum;
}

double gto_overlap(GTO &gto1, GTO &gto2) {
	return overlap(gto1.alpha, gto1.l, gto1.m, gto1.n, gto1.r,
		gto2.alpha, gto2.l, gto2.m, gto2.n, gto2.r);
}

double overlap(double &alpha1, int l1, int m1, int n1, Vector3 &a,
	double &alpha2, int l2, int m2, int n2, Vector3 &b) {

	if(l1 < 0 || l2 < 0 || m1 < 0 || m2 < 0 || n1 < 0 || n2 < 0) {
		return 0.0;
	}

	const double pi = 3.14159265359;

	double rab2 = dist2(a,b);
	double gamma = alpha1 + alpha2;
	Vector3 p = gaussian_product_center(alpha1, a, alpha2, b);

	double pre = pow(pi / gamma,1.5) * exp(-alpha1 * alpha2 * rab2 / gamma);
	double wx = overlap_1D(l1, l2, p.x-a.x, p.x-b.x, gamma);
	double wy = overlap_1D(m1, m2, p.y-a.y, p.y-b.y, gamma);
	double wz = overlap_1D(n1, n2, p.z-a.z, p.z-b.z, gamma);

	return pre*wx*wy*wz;
}

double overlap_1D(unsigned int l1, unsigned int l2, double x1, double x2, double gamma) {
	double sum = 0;

	for(int i=0; i <= 0.5*(l1+l2); i++) {
		sum += binomial_prefactor(2*i, l1, l2, x1, x2) * fact2(2*i-1)/pow(2*gamma,i);
	}

	return sum;
}
