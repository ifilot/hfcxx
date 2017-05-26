/**************************************************************************
 *   basis.cpp  --  This file is part of HFCXX.                           *
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

#include "basis.h"

Basis::Basis() {
    basisset = "undefined";
}

Basis::Basis(std::string basissett) {
    basisset = basissett;
}

void Basis::setType(std::string basissett) {
    basisset = basissett;
}

void Basis::set(std::string type, unsigned int z, Vec3 r) {
    gtos.clear();
    if(basisset.compare("sto-3g") == 0) {
        addGTOs_sto3g(type, z, r);
    } else if(basisset.compare("sto-6g") == 0) {
        addGTOs_sto6g(type, z, r);
    } else {
        std::cout << "Unrecognized basis set" << std::endl;
        exit(1);
    }
};

std::vector<GTO> Basis::getGTOs() const{
    return gtos;
}

    void Basis::addGTO_s(double alpha, double c, Vec3 r) {
    gtos.push_back(GTO(c, r, alpha, 0,0,0));
    }

    void Basis::addGTO_px(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 1,0,0));
    }

    void Basis::addGTO_py(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 0,1,0));
    }

    void Basis::addGTO_pz(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 0,0,1));
    }

    void Basis::addGTO_dx2(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 2,0,0));
    }

    void Basis::addGTO_dxy(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 1,1,0));
    }

    void Basis::addGTO_dxz(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 1,0,1));
    }

    void Basis::addGTO_dy2(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 0,2,0));
    }

    void Basis::addGTO_dyz(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 0,1,1));
    }

    void Basis::addGTO_dz2(double alpha, double c, Vec3 r) {
     gtos.push_back(GTO(c, r, alpha, 0,0,2));
    }
