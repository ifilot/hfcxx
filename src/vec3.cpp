/**************************************************************************
 *   vec3.cpp  --  This file is part of HFCXX.                            *
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

#include "vec3.h"

Vec3::Vec3() { /* default constructor */
    x = y = z =0;
}

Vec3::Vec3(const double xx, const double yy, const double zz) {
    x = xx;
    y = yy;
    z = zz;
}

Vec3::Vec3(const Vec3 &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}

const double Vec3::getx() const {
    return x;
}

const double Vec3::gety() const {
    return y;
}

const double Vec3::getz() const {
    return z;
}
