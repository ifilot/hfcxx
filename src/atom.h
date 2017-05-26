/**************************************************************************
 *   atom.h  --  This file is part of HFCXX.                              *
 *                                                                        *
 *   Copyright (C) 2012, Ivo Filot                                        *
 *                                                                        *
 *   HFCXX is free software:                                              *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   HFCXX is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/

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
