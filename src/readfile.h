/**************************************************************************
 *   readfile.h  --  This file is part of HFCXX.                          *
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

#ifndef _READFILE_H
#define _READFILE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include "strfunc.h"

class InputFile {
    private:
    std::string filename;
    std::ifstream infile;
    std::vector<std::string> lines;
    bool isOpen;

    public:
    InputFile(); /* default constructor */
    InputFile(std::string); /* constructor taking filename as input */
    ~InputFile();   /* default destructor */
    void readFile(std::vector<std::string> &);
    void dump();

    private: /* utility functions */
    void init();    /* initialization functions */
    void open(); /* open file for reading */
    void read(); /* read the file */
    void close(); /* close the file */
    void reset(); /* resets the pointer to the start of the file */
};

#endif // _READFILE_H
