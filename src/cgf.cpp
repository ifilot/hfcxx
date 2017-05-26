/**************************************************************************
 *   cgf.cpp  --  This file is part of HFCXX.                             *
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

#include "cgf.h"

CGF::CGF(const std::string typee, const unsigned int z, const Vec3 &rr, std::vector<GTO> gtoss) {
    r = rr;
    type = typee;
    gtos = gtoss;
}

std::ostream& operator <<(std::ostream &os,const CGF &rhs) {

    os << "\t\t******* ";

    os << rhs.type << " orbital";
    os << " *******" << std::endl;

    for(unsigned int i=0; i<rhs.gtos.size(); i++) {
        os << rhs.gtos[i] << std::endl;
    }

    return os;
}

const std::string CGF::orb() const {
    return type;
}
