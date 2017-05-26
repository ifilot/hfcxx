/**************************************************************************
 *   output.h  --  This file is part of HFCXX.                            *
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

#ifndef _OUTPUT_H
#define _OUTPUT_H

#include<iostream>
#include<sstream>
#include<vector>
#include "version.h"
#include "molecule.h"
#include "matrix.h"

class Output{
    private:
    std::string spacer;

    public:
    Output();
    void print_version();
    void print_geometry(Molecule &mol);
    void print_summary(unsigned int iter, double en, unsigned int nrat, unsigned int nrorbs, unsigned int bss);
    void print_calculation_time(double time);
    void print_orbitals(const std::vector<double> &molorben, const std::vector<std::string> &orblist, const MatDoub &C, unsigned int nrelec);
};

#endif //_OUTPUT_H
