#include "atom.h"

Atom::Atom(const unsigned int Zz, const double xx, const double yy, const double zz) {
	r = Vector3(xx, yy, zz);
	Z = Zz;
}

std::ostream & operator << (std::ostream &os, const Atom &rhs) {
	os << rhs.ps();

	return os << "\t" << rhs.x() << "\t" << rhs.y() << "\t" << rhs.z();
}

const std::string Atom::ps() const {
	std::vector<std::string> symbols;

	symbols.push_back("H");
	symbols.push_back("He");
	symbols.push_back("Li");
	symbols.push_back("Be");
	symbols.push_back("B");
	symbols.push_back("C");
	symbols.push_back("N");

	return symbols[Z-1];
}

const double Atom::x() const {
	return r.x;
}

const double Atom::y() const {
	return r.y;
}

const double Atom::z() const {
	return r.z;
}
