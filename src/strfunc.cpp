/**************************************************************************
 *   strfunc.cpp  --  This file is part of HFCXX.                         *
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
 
/*
 * the functions below, with exception of strtrim, are taken from
 * http://www.zedwood.com/
 */

#include "strfunc.h"

using namespace std;

size_t strpos(const string &haystack, const string &needle)
{
    int sleng = haystack.length();
    int nleng = needle.length();

    if (sleng==0 || nleng==0)
        return string::npos;

    for(int i=0, j=0; i<sleng; j=0, i++ )
    {
        while (i+j<sleng && j<nleng && haystack[i+j]==needle[j])
            j++;
        if (j==nleng)
            return i;
    }
    return string::npos;
}

string& str_replace(const string &search, const string &replace, string 
&subject)
{
    string buffer;
    
    int sealeng = search.length();
    int strleng = subject.length();

    if (sealeng==0) 
        return subject;//no change

    for(int i=0, j=0; i<strleng; j=0 )
    {
        while (i+j<strleng && j<sealeng && subject[i+j]==search[j])
            j++;
        if (j==sealeng)//found 'search'
        {
            buffer.append(replace);
            i+=sealeng;
        }
        else
        {
            buffer.append( &subject[i++], 1);
        }
    }
    subject = buffer;
    return subject;
}

string substr(const string &str, int start)
{
    return substr(str,start,str.length());
}

string substr(const string &str, int start, int length)
{
    if (start  < 0 ) start+=str.length();
    if (length < 0 ) length=str.length()+length-start;
    if (length < 0 ) return "";
    return str.substr(start,length);
}

std::string& strtrim(std::string &subject) {
	for(int i=0; i<=10; i++) {
		subject = str_replace("\t"," ",subject);
	}
	
	for(int i=0; i<=10; i++) {
		subject = str_replace("  "," ",subject);
	}

	if(strpos(subject," ")==0) {
		subject = substr(subject,1);
	}

	if(strpos(subject,"\t")==0) {
		subject = substr(subject,1);
	}

	return subject;
}

vector<string> explode( const string &delimiter, const string &str)
{
    vector<string> arr;

    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng==0)
        return arr;//no change

    int i=0; 
    int k=0;
    while( i<strleng )
    {
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
            j++;
        if (j==delleng)//found delimiter
        {
            arr.push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        }
        else
        {
            i++;
        }
    }
    arr.push_back(  str.substr(k, i-k) );
    return arr;
}
