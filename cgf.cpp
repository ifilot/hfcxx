#include "cgf.h"

CGF::CGF(const std::string typee, const double zetaa, const Vector3 rr) {
	zeta = zetaa;
	r = rr;
	type = typee;

	/* options for setting up the GTOs */
	if(type.compare("1s")==0) {
		gtos.push_back(GTO(0.444635,r,0.168856,0,0,0));
		gtos.push_back(GTO(0.535328,r,0.623913,0,0,0));
		gtos.push_back(GTO(0.154329,r,3.42525,0,0,0));
	}
}
