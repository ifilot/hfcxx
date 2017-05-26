/**************************************************************************
 *   clock.h  --  This file is part of HFCXX.                             *
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

#ifndef _CLOCK_H
#define _CLOCK_H

#include<sys/time.h>
#include<cstddef>

class Clock{
    private:
    struct timeval time1,time2;
    long mtime, seconds, useconds;
    public:
    Clock(); /* default constructor */
    void tic(); /* starts / resets the clock */
    void toc(); /* pauses the clock */
    double passed(); /* returns the time in seconds */
};

#endif //_CLOCK_H
