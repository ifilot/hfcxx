/*
 * nuclear.cpp
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description:
 */
 
#include "nuclear.h"

double cgf_nuclear(CGF &cgf1, CGF &cgf2, const Atom &a) {
	unsigned int i = cgf1.gtos.size();
	unsigned int j = cgf2.gtos.size();

	double sum = 0;

	for(unsigned int k = 0; k < i; k++) {
		for(unsigned int l = 0; l < j; l++) {
			sum += cgf1.gtos[k].c * cgf2.gtos[l].c * gto_nuclear(cgf1.gtos[k], cgf2.gtos[l], a.gr() );
		}
	}

	return sum * a.nucl_chg();
}

double gto_nuclear(GTO &gto1, GTO &gto2, const Vec3 &c) {

	return nuclear(gto1.r, gto1.norm, gto1.l, gto1.m, gto1.n, gto1.alpha, gto2.r, gto2.norm, gto2.l, gto2.m, gto2.n, gto2.alpha, c);
}

double nuclear(const Vec3 a, double norm1, int l1, int m1, int n1, double alpha1, const Vec3 b, double norm2, int l2, int m2, int n2, double alpha2, const Vec3 c) {
	static const double pi = 3.14159265359;
	double gamma = alpha1 + alpha2;

	Vec3 p = gaussian_product_center(alpha1, a, alpha2, b);
	double rab2 = dist2(a,b);
	double rcp2 = dist2(c,p);

	std::vector<double> ax = A_array(l1,l2,p.getx()-a.getx(),p.getx()-b.getx(),p.getx()-c.getx(),gamma);
	std::vector<double> ay = A_array(m1,m2,p.gety()-a.gety(),p.gety()-b.gety(),p.gety()-c.gety(),gamma);
	std::vector<double> az = A_array(n1,n2,p.getz()-a.getz(),p.getz()-b.getz(),p.getz()-c.getz(),gamma);

	double sum = 0.0;

	for(int i=0; i<=l1+l2;i++) {
		for(int j=0; j<=m1+m2;j++) {
			for(int k=0; k<=n1+n2;k++) {
				sum += ax[i] * ay[j] * az[k] * Fgamma(i+j+k,rcp2*gamma);
			}
		}
	}

	return -norm1 * norm2 * 2 * pi / gamma * exp(-alpha1*alpha2*rab2/gamma) * sum;
}

std::vector<double> A_array(const int l1, const int l2, const double pa, const double pb, const double cp, const double g) {
	int imax = l1 + l2 + 1;
	std::vector<double> arrA(imax, 0);

	for(int i=0; i<imax; i++) {
		for(int r=0; r<=i/2; r++) {
			for(int u=0; u<=(i-2*r)/2; u++) {
				int iI = i - 2 * r - u;
				arrA[iI] = A_term(i, r, u, l1, l2, pa, pb, cp, g);
			}
		}
	}

	return arrA;
}

double A_term(const int i, const int r, const int u, const int l1, const int l2, const double pax, const double pbx, const double cpx, const double gamma) {
	return 	pow(-1,i) * binomial_prefactor(i,l1,l2,pax,pbx)*
					pow(-1,u) * fact(i)*pow(cpx,i-2*r-2*u)*
					pow(0.25/gamma,r+u)/fact(r)/fact(u)/fact(i-2*r-2*u);
}
