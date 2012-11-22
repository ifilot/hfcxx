/*
 * molecule.cpp
 *
 * Author: Ivo Filot
 *
 */

#include "molecule.h"

Molecule::Molecule(){}; /* default constructor */

void Molecule::addAtom(const Atom &at) {
	atoms.push_back(at);
}

void Molecule::addAtom(const std::string symbolin, const double xx, const double yy, const double zz) {
	Atom at(symbolin, xx, yy, zz);
	atoms.push_back(at);
}

void Molecule::addAtom(const unsigned int Zz, const double xx, const double yy, const double zz) {
	Atom at(Zz, xx, yy, zz);
	atoms.push_back(at);
}
