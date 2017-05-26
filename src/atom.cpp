/**************************************************************************
 *   atom.cpp  --  This file is part of HFCXX.                            *
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

#include "atom.h"

Atom::Atom(const unsigned int Zz, const double xx, const double yy, const double zz, Basis &basisset) {
    r = Vec3(xx, yy, zz);
    Z = Zz;
    nrelec = Z;

    addWavefunctions(basisset);
}

Atom::Atom(const std::string elementin, const double xx, const double yy, const double zz, Basis &basisset) {
    element = elementin;
    r = Vec3(xx, yy, zz);
    Z = e2z(element);
    nrelec = Z;

    addWavefunctions(basisset);
}

std::ostream & operator << (std::ostream &os, const Atom &rhs) {
    os << rhs.ps();

    os << std::setprecision(10) << std::setiosflags(std::ios::fixed);

    os << "\t" << rhs.x() << "\t" << rhs.y() << "\t" << rhs.z() << std::endl;
    os << "----------------------------------------------------------------" << std::endl;

    for(unsigned int i=0; i<rhs.wavefunctions.size();i++) {
        os << rhs[i];
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
    symbols.push_back("O");
    symbols.push_back("F");
    symbols.push_back("Ne");

    return symbols[Z-1];
}

const double Atom::x() const {
    return r.getx();
}

const double Atom::y() const {
    return r.gety();
}

const double Atom::z() const {
    return r.getz();
}

const Vec3 Atom::gr() const {
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

void Atom::addWavefunctions(Basis &basis){

    if(Z==1 || Z==2) {
        basis.set("1s", Z,r);
        wavefunctions.push_back(CGF("1s", Z, r, basis.getGTOs() ));
        nrwav = 1;
    }
    if(Z==3 || Z==4) {
        basis.set("1s", Z,r);
        wavefunctions.push_back(CGF("1s", Z, r, basis.getGTOs() ));
        basis.set("2s", Z,r);
        wavefunctions.push_back(CGF("2s", Z, r, basis.getGTOs() ));
        nrwav = 2;
    }
    if(Z>=5 && Z<=10) {
        basis.set("1s", Z,r);
        wavefunctions.push_back(CGF("1s", Z, r, basis.getGTOs() ));
        basis.set("2s", Z,r);
        wavefunctions.push_back(CGF("2s", Z, r, basis.getGTOs() ));
        basis.set("2px", Z,r);
        wavefunctions.push_back(CGF("2px", Z, r, basis.getGTOs() ));
        basis.set("2py", Z,r);
        wavefunctions.push_back(CGF("2py", Z, r, basis.getGTOs() ));
        basis.set("2pz", Z,r);
        wavefunctions.push_back(CGF("2pz", Z, r, basis.getGTOs() ));
        nrwav = 5;
    }
}

const CGF& Atom::operator[](const unsigned int i) const {
    return wavefunctions[i];
}

const unsigned int Atom::nrorbs() const {
    return nrwav;
}

const unsigned int Atom::nrelecs() const {
    return nrelec;
}

const unsigned int Atom::nucl_chg() const {
    return Z;
}
