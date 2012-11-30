/*
 * molecule.cpp
 *
 * Author: Ivo Filot
 *
 */

#include "molecule.h"

/* default constructor */
Molecule::Molecule() {
	nrat = 0;
}

void Molecule::addAtom(const Atom &at) {
	atoms.push_back(at);
	nrat++;
}

void Molecule::addAtom(const std::string symbolin, const double xx, const double yy, const double zz) {
	Atom at(symbolin, xx, yy, zz);
	atoms.push_back(at);
	nrat++;
}

void Molecule::addAtom(const unsigned int Zz, const double xx, const double yy, const double zz) {
	Atom at(Zz, xx, yy, zz);
	atoms.push_back(at);
	nrat++;
}

std::ostream & operator << (std::ostream &os, const Molecule &rhs) {
	for(unsigned int i=0; i<rhs.atoms.size();i++) {
		os << "(" << i+1 << ")\t" << rhs.atoms[i] << std::endl;
	}

	return os;
}

const unsigned int Molecule::nratoms() const{
	return nrat;
}

const Atom& Molecule::operator[](const unsigned int i) const {
  return atoms[i];
}

void Molecule::read(std::string file) {
	/* read file to construct molecule here */
}
