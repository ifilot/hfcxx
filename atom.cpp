/*
 * atom.cpp
 *
 * Author: Ivo Filot
 *
 */

#include "atom.h"

Atom::Atom(const unsigned int Zz, const double xx, const double yy, const double zz) {
	r = Vector3(xx, yy, zz);
	Z = Zz;

	addWavefunctions();
}

Atom::Atom(const std::string elementin, const double xx, const double yy, const double zz) {
	element = elementin;
	r = Vector3(xx, yy, zz);
	Z = e2z(element);

	addWavefunctions();
}

std::ostream & operator << (std::ostream &os, const Atom &rhs) {
	os << rhs.ps();

	os << std::setprecision(10) << std::setiosflags(std::ios::fixed);

	os << "\t" << rhs.x() << "\t" << rhs.y() << "\t" << rhs.z() << std::endl;
	os << "----------------------------------------------------------------" << std::endl;

	for(unsigned int i=0; i<rhs.wavefunctions.size();i++) {
		os << rhs.wavefunctions[i];
	}

	os << "----------------------------------------------------------------" << std::endl;

	return os;
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

const Vector3 Atom::gr() const {
	return r;
}

unsigned int Atom::e2z(const std::string &symbol) const {
	if(symbol.compare("H") == 0) {
		return 1;
	}
		if(symbol.compare("He") == 0) {
		return 2;
	}
		if(symbol.compare("Li") == 0) {
		return 3;
	}
		if(symbol.compare("Be") == 0) {
		return 4;
	}
		if(symbol.compare("B") == 0) {
		return 5;
	}
		if(symbol.compare("C") == 0) {
		return 6;
	}
		if(symbol.compare("N") == 0) {
		return 7;
	}
		if(symbol.compare("O") == 0) {
		return 8;
	}
		if(symbol.compare("F") == 0) {
		return 9;
	}
		if(symbol.compare("Ne") == 0) {
		return 10;
	}

	return 0;
}

std::string Atom::z2e(const unsigned int &z) const {
	if(z==1) {
		return "H";
	}
	if(z==2) {
		return "He";
	}
	if(z==3) {
		return "Li";
	}
	if(z==4) {
		return "Be";
	}
	if(z==5) {
		return "B";
	}
	if(z==6) {
		return "C";
	}
	if(z==7) {
		return "N";
	}
	if(z==8) {
		return "O";
	}
	if(z==9) {
		return "F";
	}
	if(z==10) {
		return "Ne";
	}

	return "undefined";
}

void Atom::addWavefunctions(){
	if(Z==1 || Z==2) {
		wavefunctions.push_back(CGF("1s", Z, r));
	}
	if(Z==3 || Z==4) {
		wavefunctions.push_back(CGF("1s", Z, r));
		wavefunctions.push_back(CGF("2s", Z, r));
	}
	if(Z>=5 && Z<=10) {
		wavefunctions.push_back(CGF("1s", Z, r));
		wavefunctions.push_back(CGF("2s", Z, r));
		wavefunctions.push_back(CGF("2p", Z, r));
	}
	
}

CGF* Atom::operator[](const unsigned int i) {
	return &wavefunctions[i];
}

const CGF* Atom::operator[](const unsigned int i) const {
	return &wavefunctions[i];
}

