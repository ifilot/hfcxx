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
	const double pi = 3.14159265359;

	double rab2 = dist2(gto1.r,gto2.r);
	double gamma = gto1.alpha + gto2.alpha;
	Vector3 p = gaussian_product_center(gto1.alpha, gto1.r, gto2.alpha, gto2.r);

	double pre = pow(pi / gamma,1.5) * exp(-gto1.alpha * gto2.alpha * rab2 / gamma);
	double wx = overlap_1D(gto1.l, gto2.l, p.x-gto1.x, p.x-gto2.x, gamma);
	double wy = overlap_1D(gto1.m, gto2.m, p.y-gto1.y, p.y-gto2.y, gamma);
	double wz = overlap_1D(gto1.n, gto2.n, p.z-gto1.z, p.z-gto2.z, gamma);

	return pre*wx*wy*wz;
}

double overlap_1D(unsigned int l1, unsigned int l2, double x1, double x2, double gamma) {
	double sum = 0;

	for(unsigned int i=0; i <= 0.5*(l1+l2); i++) {
		sum += binomial_prefactor(2*i, l1, l2, x1, x2) * fact2(2*i-1)/pow(2*gamma,i);
	}

	return sum;
}
