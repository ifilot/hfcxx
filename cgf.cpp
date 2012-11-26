/*
 * cgf.cpp
 *
 * defines contracted gaussian function class
 *
 * Author: Ivo Filot
 */

#include "cgf.h"

CGF::CGF(const std::string &typee, const unsigned int &z, const Vector3 &rr) {
	r = rr;
	type = typee;

	/* options for setting up the GTOs */
	addGTOs_sto3g(type,z);
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

void CGF::addGTO_s(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 0,0,0));
}

void CGF::addGTO_px(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 1,0,0));
	gtos.push_back(GTO(c, r, alpha, 0,1,0));
	gtos.push_back(GTO(c, r, alpha, 0,0,1));
}

void CGF::addGTO_py(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 0,1,0));
}

void CGF::addGTO_pz(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 0,0,1));
}

void CGF::addGTO_dx2(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 2,0,0));
}

void CGF::addGTO_dxy(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 1,1,0));
}

void CGF::addGTO_dxz(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 1,0,1));
}

void CGF::addGTO_dy2(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 0,2,0));
}

void CGF::addGTO_dyz(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 0,1,1));
}

void CGF::addGTO_dz2(double alpha, double c) {
	gtos.push_back(GTO(c, r, alpha, 0,0,2));
}

#include "basis-sto3g.cpp"
