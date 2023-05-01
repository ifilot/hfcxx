/**************************************************************************
 *   factorial.h  --  This file is part of HFCXX.                         *
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

#ifndef _FACTORIAL_H
#define _FACTORIAL_H

inline static const int fact_recursive(int n){
    return n <= 1 ? 1 : n * fact_recursive(n-1);
}

static const int fact(int n){
    static const int factorials[11] = {
        1,
        1,
        2,
        6,
        24,
        120,
        720,
        5040,
        40320,
        362880,
        3628880
    };

    if(n < 11) {
        if(n < 0) {
            return 1;
        } else {
            return factorials[n];
        }
    } else {
        return fact_recursive(n);
    }
}

inline static const int fact2_recursive(int n){
    return n <= 1 ? 1 : n * fact2_recursive(n-2);
}

/* double factorial function = 1*3*5*...*n */
static const int fact2(int n){
    static const int factorials2[11] = {
        1,
        1,
        2,
        3,
        8,
        15,
        48,
        105,
        384,
        945,
        3840
    };

    if(n < 11) {
        if(n < 0) {
            return 1;
        } else {
            return factorials2[n];
        }
    } else {
        return fact2_recursive(n);
    }
}

#endif //_FACTORIAL_H
