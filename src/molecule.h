/**************************************************************************
 *   molecule.h  --  This file is part of HFCXX.                          *
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

#ifndef _MOLECULE_H
#define _MOLECULE_H

#include<string>
#include<vector>
#include "atom.h"
#include "basis.h"
#include "strfunc.h"
#include "readfile.h"

class Molecule{
    private:
    std::vector<Atom> atoms;
    unsigned int nrat;
    Basis basis;
    std::string basisset;
    unsigned int charge;

    public:
    Molecule(); /* default constructor */
    void read(std::string file); /* read molecule from file */
    void addAtom(const Atom &at);
    void addAtom(const std::string symbolin, const double xx, const double yy, const double zz);
    void addAtom(const unsigned int Zz, const double xx, const double yy, const double zz);
    friend std::ostream & operator << (std::ostream &os, const Molecule &rhs);
    const unsigned int nratoms() const;
    const Atom& operator[](const unsigned int i) const;
};

#endif //_MOLECULE_H
