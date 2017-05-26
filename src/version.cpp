/**************************************************************************
 *   version.cpp  --  This file is part of HFCXX.                         *
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

#include "version.h"

std::string version() {
	std::stringstream str;
	std::string prog_name = "hfcxx";
	std::string version_number = PACKAGE_VERSION;
	std::string author = "Ivo Filot <ivo@ivofilot.nl>";
	std::string date = __DATE__;
	std::string time = __TIME__;
	std::string compiler_version = __VERSION__;

	str << "executing: " << prog_name << " version " << version_number << std::endl;
	//std::cout << "tracking number: " << compile_counter << std::endl;
	str << "compiled on: " << date << " " << time << std::endl;
	str << "compiler: gcc " << compiler_version << std::endl;
	str << "author: " << author << std::endl;
	str << std::endl;

	std::string out = str.str();
	return out;
}
