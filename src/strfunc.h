/*
 * strfunc.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: String modification functions based on PHP functions
 */
 
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
