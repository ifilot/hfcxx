/**************************************************************************
 *   main.cpp  --  This file is part of HFCXX.                            *
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

#include<iostream>
#include <iomanip>
#include <string.h>
#include "hf.h"
#include "clock.h"
#include "output.h"

int main(int argc, char *argv[]) {
    // parse the arguments
    if(argc == 1) {
        std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
        std::cout << "Please provide a valid input file" << std::endl;
        return 0;
    }

    // initialize an output object
    Output out;
    // print the version to
    out.print_version();

    std::string filename;
    bool debug = false;

    /* parse arguments */
    if(!strcmp(argv[argc-2],"-m")) {
        debug = true;
    }

    if(argc > 1) {
        filename = argv[argc-1];
    }

    /* output compile information on execution */
    version();

    /* keep track of the time */
    Clock clock;

    /* read molecule from geometry file */
    Molecule mol;
    mol.read(filename);
    out.print_geometry(mol);

    /* perform HF calculation */
    HF hf;
    hf.debug = debug;
    hf.molecule(mol);
    hf.run();

    /* output calculation time */
    clock.toc();
    out.print_calculation_time(clock.passed());

    #ifdef _WIN32
        std::cout << "Press ENTER to close" << std::endl;
        std::cin.get();
    #endif //_check if compiled on Win32

    return 0;
}
