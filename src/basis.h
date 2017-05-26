/**************************************************************************
 *   basis.h  --  This file is part of HFCXX.                             *
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

#ifndef _BASIS_H
#define _BASIS_H

#include<string>
#include <stdlib.h>
#include "gto.h"
#include "vec3.h"

class Basis{
    private:
    std::vector<GTO> gtos;
    std::string basisset;

    public:
    Basis();
    Basis(std::string basisset);
    void set(std::string type, unsigned int z, Vec3 r);
    void setType(std::string basissett);
    std::vector<GTO> getGTOs() const;

    private:
    void addGTOs_sto3g(std::string type, unsigned int z, Vec3 r);
    void addGTOs_sto6g(std::string type, unsigned int z, Vec3 r);

    /* GTOs for sto-xg basis sets */
    void addGTO_s(double alpha, double c, Vec3 r);
    void addGTO_px(double alpha, double c, Vec3 r);
    void addGTO_py(double alpha, double c, Vec3 r);
    void addGTO_pz(double alpha, double c, Vec3 r);
    void addGTO_dx2(double alpha, double c, Vec3 r);
    void addGTO_dxy(double alpha, double c, Vec3 r);
    void addGTO_dxz(double alpha, double c, Vec3 r);
    void addGTO_dy2(double alpha, double c, Vec3 r);
    void addGTO_dyz(double alpha, double c, Vec3 r);
    void addGTO_dz2(double alpha, double c, Vec3 r);
};

#endif //_BASIS_H
