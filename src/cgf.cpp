/*
 * cgf.cpp
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description:
 */

#include "cgf.h"

CGF::CGF(const std::string typee, const unsigned int z, const Vector3 &rr, std::vector<GTO> gtoss) {
	r = rr;
	type = typee;
	gtos = gtoss;

	
}

std::ostream& operator <<(std::ostream &os,const CGF &rhs) {

	os << "\t\t******* ";

	os << rhs.type << " orbital";
	os << " *******" << std::endl;

	for(unsigned int i=0; i<rhs.gtos.size(); i++) {
		os << rhs.gtos[i] << std::endl;
	}

	return os;
}

const std::string CGF::orb() const {
	return type;
}
