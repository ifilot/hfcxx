/*
 * atom.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: header file for atom class
 */

#ifndef _ATOM_H
#define _ATOM_H

#include<iostream>
#include<string>
#include<vector>
#include "vec3.h"
#include "cgf.h"
#include "basis.h"

class Atom{
	private:
	unsigned int Z; /* atomic number, i.e. H=1, He=2, Li=3... */
	Vec3 r; /* position of atom */
	std::string element;
	std::vector<CGF> wavefunctions;
	unsigned int nrwav; /* number of wavefunctions */
	unsigned int nrelec; /* number of electrons */

	public:
	Atom(const std::string symbolin, const double xx, const double yy, const double zz, Basis &basis);
	Atom(const unsigned int Zz, const double xx, const double yy, const double zz, Basis &basis);

	friend std::ostream & operator << (std::ostream &os, const Atom &rhs);

	private:
	const double x() const;
	const double y() const;
	const double z() const;
	unsigned int e2z(const std::string &elementin) const;
	std::string z2e(const unsigned int &z) const;
	void addWavefunctions(Basis &basis);

	public:
	const std::string ps() const; /* print symbol */
	const Vec3 gr() const;
	const unsigned int nrorbs() const;
	const CGF& operator[](const unsigned int i) const;
	const unsigned int nrelecs() const;
	const unsigned int nucl_chg() const;
};

#endif // _ATOM_H
