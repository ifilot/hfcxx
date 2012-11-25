/*
 * cgf.cpp
 *
 * defines contracted gaussian function class
 *
 * Author: Ivo Filot
 */

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

	/* (1) HYDROGEN */
	if(type.compare("1s")==0 && z==1) {
		gtos.push_back(GTO(0.444635,r,0.168856,0,0,0));
		gtos.push_back(GTO(0.535328,r,0.623913,0,0,0));
		gtos.push_back(GTO(0.154329,r,3.42525,0,0,0));
	}
	/* (2) HELIUM */
	if(type.compare("1s")==0 && z==2) {
		gtos.push_back(GTO(0.444635,r,0.168856,0,0,0));
		gtos.push_back(GTO(0.535328,r,0.623913,0,0,0));
		gtos.push_back(GTO(0.154329,r,3.42525,0,0,0));
	}
	/* (8) OXYGEN */
	if(type.compare("1s")==0 && z==8) {
		gtos.push_back(GTO(0.15432897000000001,r,130.70931999999999,0,0,0));
		gtos.push_back(GTO(0.53532813999999995,r,23.808861,0,0,0));
		gtos.push_back(GTO(0.44463454000000002,r,6.4436083000000002,0,0,0));
	}
	if(type.compare("2s")==0 && z==8) {
		gtos.push_back(GTO(-0.099967230000000004,r,5.0331513000000001,0,0,0));
		gtos.push_back(GTO(0.39951282999999999,r,1.1695960999999999,0,0,0));
		gtos.push_back(GTO(0.70011546999999996,r,0.38038899999999998,0,0,0));
	}
	if(type.compare("2px")==0 && z==8) {
		gtos.push_back(GTO(0.15591627,r,5.0331513000000001,1,0,0));
		gtos.push_back(GTO(0.60768372000000004,r,1.1695960999999999,1,0,0));
		gtos.push_back(GTO(0.39195739000000002,r,0.38038899999999998,1,0,0));
	}
	if(type.compare("2py")==0 && z==8) {
		gtos.push_back(GTO(0.15591627,r,5.0331513000000001,0,1,0));
		gtos.push_back(GTO(0.60768372000000004,r,1.1695960999999999,0,1,0));
		gtos.push_back(GTO(0.39195739000000002,r,0.38038899999999998,0,1,0));
	}
	if(type.compare("2pz")==0 && z==8) {
		gtos.push_back(GTO(0.15591627,r,5.0331513000000001,0,0,1));
		gtos.push_back(GTO(0.60768372000000004,r,1.1695960999999999,0,0,1));
		gtos.push_back(GTO(0.39195739000000002,r,0.38038899999999998,0,0,1));
	}
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
