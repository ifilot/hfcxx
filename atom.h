#ifndef _ATOM_H
#define _ATOM_H

#include<iostream>
#include "vector.h"
#include<string>
#include<vector>

class Atom{
	private:
	unsigned int Z; /* atomic number, i.e. H=1, He=2, Li=3... */
	Vector3 r; /* position of atom */

	public:
	Atom(const unsigned int Zz, const double xx, const double yy, const double zz); /* default constructor */

	friend std::ostream & operator << (std::ostream &os, const Atom &rhs);

	private:
	const std::string ps() const; /* print symbol */
	const double x() const;
	const double y() const;
	const double z() const;

	public:
	const Vector3 gr() const;

};

#endif // _ATOM_H
