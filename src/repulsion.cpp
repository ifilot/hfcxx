#include "repulsion.h"

double cgf_repulsion(const CGF &cgf1,const CGF &cgf2,const CGF &cgf3,const CGF &cgf4) {
	double sum = 0;

	int size1 = cgf1.gtos.size();
	int size2 = cgf2.gtos.size();
	int size3 = cgf3.gtos.size();
	int size4 = cgf4.gtos.size();

	for(int i=0; i< size1; i++) {
		for(int j=0; j< size2; j++) {
			for(int k=0; k < size3; k++) {
				for(int l=0; l < size4; l++) {
					double pre = cgf1.gtos[i].c * cgf2.gtos[j].c * cgf3.gtos[k].c * cgf4.gtos[l].c;
					sum += pre * gto_repulsion(cgf1.gtos[i],cgf2.gtos[j],cgf3.gtos[k],cgf4.gtos[l]);
				}
			}
		}
	}

	return sum;
}

double gto_repulsion(const GTO &gto1, const GTO &gto2, const GTO &gto3, const GTO &gto4) {

	return coulomb_repulsion(gto1.r, gto1.norm, gto1.l, gto1.m, gto1.n, gto1.alpha,
													 gto2.r, gto2.norm, gto2.l, gto2.m, gto2.n, gto2.alpha,
													 gto3.r, gto3.norm, gto3.l, gto3.m, gto3.n, gto3.alpha,
												   gto4.r, gto4.norm, gto4.l, gto4.m, gto4.n, gto4.alpha);
}

double coulomb_repulsion( const Vector3 &a, const double &norma, const int la, const int ma, const int na, const double &alphaa,
													const Vector3 &b, const double &normb, const int lb, const int mb, const int nb, const double &alphab,
													const Vector3 &c, const double &normc, const int lc, const int mc, const int nc, const double &alphac,
													const Vector3 &d, const double &normd, const int ld, const int md, const int nd, const double &alphad) {

	static const double pi = 3.14159265359;
	double rab2 = dist2(a,b);
	double rcd2 = dist2(c,d);

	Vector3 p = gaussian_product_center(alphaa, a, alphab, b);
	Vector3 q = gaussian_product_center(alphac, c, alphad, d);

	double rpq2 = dist2(p,q);

	double gamma1 = alphaa + alphab;
	double gamma2 = alphac + alphad;
	double delta = 0.25 * (1.0 / gamma1 + 1.0 / gamma2);

	std::vector<double> bx = B_array(la, lb, lc, ld, p.x, a.x, b.x, q.x, c.x, d.x, gamma1, gamma2, delta);
	std::vector<double> by = B_array(ma, mb, mc, md, p.y, a.y, b.y, q.y, c.y, d.y, gamma1, gamma2, delta);
	std::vector<double> bz = B_array(na, nb, nc, nd, p.z, a.z, b.z, q.z, c.z, d.z, gamma1, gamma2, delta);

	double sum = 0.0;
	for(int i=0; i<=(la+lb+lc+ld); i++) {
		for(int j=0; j<=(ma+mb+mc+md); j++) {
			for(int k=0; k<=(na+nb+nc+nd); k++) {
				sum += bx[i]*by[j]*bz[k]*Fgamma(i+j+k,0.25*rpq2/delta);
			}
		}
	}

	return 2*pow(pi,2.5)/(gamma1*gamma2*sqrt(gamma1+gamma2))*
		exp(-alphaa*alphab*rab2/gamma1)*
		exp(-alphac*alphad*rcd2/gamma2)*sum*norma*normb*normc*normd;
}

std::vector<double> B_array(const int l1,const int l2,const int l3,const int l4, 
		const double &p, const double &a, const double &b, const double &q, const double &c, const double &d,
		const double g1, const double g2, const double delta) {

	int imax = l1 + l2 + l3 + l4 + 1;
	std::vector<double> arrB(imax,0);

	for(int i1=0; i1<l1+l2+1; i1++) {
		for(int i2=0; i2<l3+l4+1; i2++) {
			for(int r1=0; r1 < i1/2+1; r1++) {
				for(int r2=0; r2 < i2/2+1; r2++) {
					for(int u=0; u<(i1+i2)/2-r1-r2+1; u++) {
						int i = i1+i2-2*(r1+r2)-u;
						arrB[i] += B_term(i1,i2,r1,r2,u,l1,l2,l3,l4,
															p,a,b,q,c,d,g1,g2,delta);
					}
				}
			}
		}
	}
	return arrB;
}

double B_term(const int i1, const int i2, const int r1, const int r2, const int u, const int l1, const int l2, const int l3, const int l4,
		const double &px, const double &ax, const double &bx, const double &qx, const double &cx, const double &dx, const double &gamma1,
		const double &gamma2, const double &delta) {
	return fB(i1,l1,l2,px,ax,bx,r1,gamma1)*
		pow(-1,i2) * fB(i2,l3,l4,qx,cx,dx,r2,gamma2)*
		pow(-1,u)*fact_ratio2(i1+i2-2*(r1+r2),u)*
		pow(qx-px,i1+i2-2*(r1+r2)-2*u)/
		pow(delta,i1+i2-2*(r1+r2)-u);
}

double fB(const int i, const int l1, const int l2, const double &p, const double &a, const double &b, const int r, const double &g) {
	return binomial_prefactor(i, l1, l2, p-a, p-b) * B0(i, r, g);
}

double B0(int i, int r, double g) {
	return fact_ratio2(i,r) * pow(4*g,r-i);
}

double fact_ratio2(const int a, const int b) {
	return fact(a) / fact(b) / fact(a - 2*b);
}

const unsigned int teindex(unsigned int i, unsigned int j, unsigned int k, unsigned int l) {
	if(i < j) {
		swap(i,j);
	}
	if(k < l) {
		swap(k,l);
	}

	unsigned int ij = i * (i + 1) / 2 + j;
	unsigned int kl = k * (k + 1) / 2 + l;

	if(ij < kl) {
		swap(ij,kl);
	}

	return ij * (ij + 1) / 2 + kl;
}
