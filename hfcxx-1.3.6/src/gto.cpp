/*
 * gto.cpp
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description:
 */
 
#include "gto.h"

GTO::GTO(const double cc, const Vector3 rr, const double alphaa, const unsigned int ll, const unsigned int mm, const unsigned int nn) {
	r = rr;
	alpha = alphaa;
	l = ll;
	m = mm;
	n = nn;

	x = r.getx();
	y = r.gety();
	z = r.getz();

	c = cc;
	norm = calcnorm();
}

double GTO::calcnorm() const {
	const double pi = 3.14159265359;
	double nom = pow(2.0, 2.0*(l+m+n)+3.0/2.0)*pow(alpha,(l+m+n)+3.0/2.0);
	double denom = fact2(2*l-1)*fact2(2*m-1)*fact2(2*n-1)*pow(pi,3.0/2.0);

	return sqrt(nom / denom);
}

std::ostream& operator <<(std::ostream &os,const GTO &rhs) {
	os << std::setw(10) << std::setiosflags(std::ios::right);
	os << std::setprecision(10) << std::setiosflags(std::ios::fixed);
	os << "c = " << rhs.c << "\t" << "alpha = " << rhs.alpha << "\t" << "(l,m,n) = " << "(" 
		 << rhs.l << "," << rhs.m << "," << rhs.n << ")";

	return os;
}
