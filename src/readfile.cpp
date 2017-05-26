/**************************************************************************
 *   readfile.cpp  --  This file is part of HFCXX.                        *
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

#include "readfile.h"

InputFile::InputFile() {
    this->init();
};

InputFile::InputFile(std::string in) {
    this->init();
    this->filename = in;
}

void InputFile::init() {
    isOpen = false;
}

InputFile::~InputFile() {
    this->close();
}

void InputFile::open() {
    if(!isOpen) {
        //std::cout << "Opening file" << std::endl;
        isOpen = true;
        infile.open(filename.c_str() );
    } else {
        std::cout << "Error, file already opened" << std::endl;
    }
}

void InputFile::close() {
    if(isOpen) {
        //std::cout << "Closing file" << std::endl;
        infile.close();
    }
}

void InputFile::read() {
    this->open();
    std::string line;

    if(infile.is_open() ) {
        while(infile.good() ) {
            getline(infile,line);
            lines.push_back(line);
        }
    }

    this->reset();
}

void InputFile::readFile(std::vector<std::string> &output) {
    this->read();
    output = lines;
}

void InputFile::dump() {
    unsigned int i = 0;
    for(std::vector<std::string>::iterator it = lines.begin();
    it != lines.end(); ++it) {
        i++;
        std::cout << i << "\t" << *it << std::endl;
    }
}

void InputFile::reset() {
    infile.seekg(0);
}
