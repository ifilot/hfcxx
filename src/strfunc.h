/**************************************************************************
 *   strfunc.h  --  This file is part of HFCXX.                           *
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
 
#ifndef _STRFUNC_H
#define _STRFUNC_H

#include<string>
#include<vector>

/* strpos */
size_t strpos(const std::string &haystack, const std::string &needle);

/* strreplace */
std::string& str_replace(const std::string &search, const std::string 
&replace, std::string &subject);

/* substring (two variants) */
std::string substr(const std::string &str, int start);
std::string substr(const std::string &str, int start, int length);

/* strtrim */
std::string& strtrim(std::string &subject);

/* explode */
std::vector<std::string> explode( const std::string &delimiter, const std::string &explodeme);

#endif // _STRFUNC_H
