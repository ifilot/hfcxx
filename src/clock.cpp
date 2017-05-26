/**************************************************************************
 *   clock.cpp  --  This file is part of HFCXX.                           *
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

#include "clock.h"

Clock::Clock() {
    this->tic();
}

void Clock::tic() {
    gettimeofday(&time1, NULL);
}

void Clock::toc() {
    gettimeofday(&time2, NULL);
}

double Clock::passed() {
    seconds = time2.tv_sec - time1.tv_sec;
    useconds = time2.tv_usec - time1.tv_usec;
    mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;

    return double(mtime);
}
