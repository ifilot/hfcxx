#include "cgf.h"

CGF::CGF(const std::string typee, const Vector3 rr) {
	r = rr;
	type = typee;

	/* options for setting up the GTOs */
	if(type.compare("1s")==0) {
		gtos.push_back(GTO(0.444635,r,0.168856,0,0,0));
		gtos.push_back(GTO(0.535328,r,0.623913,0,0,0));
		gtos.push_back(GTO(0.154329,r,3.42525,0,0,0));
	}
}

CGF::CGF(const std::string &typee, const unsigned int &z, const Vector3 &rr) {
	r = rr;
	type = typee;

	/* options for setting up the GTOs */
	if(type.compare("1s")==0 && z==1) { /* 1s of H */
		gtos.push_back(GTO(0.444635,r,0.168856,0,0,0));
		gtos.push_back(GTO(0.535328,r,0.623913,0,0,0));
		gtos.push_back(GTO(0.154329,r,3.42525,0,0,0));
	}
	if(type.compare("1s")==0 && z==2) { /* 1s of He */
		gtos.push_back(GTO(0.444635,r,0.168856,0,0,0));
		gtos.push_back(GTO(0.535328,r,0.623913,0,0,0));
		gtos.push_back(GTO(0.154329,r,3.42525,0,0,0));
	}
}
