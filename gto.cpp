#include "gto.h"

GTO::GTO(const double cc, const Vector3 rr, const double alphaa, const unsigned int ll, const unsigned int mm, const unsigned int nn) {
	c = cc;
	r = rr;
	alpha = alphaa;
	l = ll;
	m = mm;
	n = nn;

	x = r.x;
	y = r.y;
	z = r.z;
}

double GTO::norm() const {
	const double pi = 3.14159265359;
	double nom = pow(2.0, 2.0*(l+m+n)+3.0/2.0)*pow(alpha,(l+m+n)+3.0/2.0);
	//std::cout << nom << std::endl;
	double denom = fact2(2*l-1)*fact2(2*m-1)*fact2(2*n-1)*pow(pi,3.0/2.0);
	//std::cout << denom << std::endl;

	return sqrt(nom / denom);
}
