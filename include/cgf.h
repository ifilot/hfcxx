/*
 * cgf.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description:
 */

#ifndef _CGF_H
#define _CGF_H

#include<iostream>
#include<vector>
#include<string>
#include "vector.h"
#include "gto.h"

/*
Contracted Gaussian Function
*/

class CGF{
	public:
	std::vector<GTO> gtos;
	Vector3 r;
	std::string type;

	public:
	CGF(const std::string typee, const unsigned int z, const Vector3 &rr, std::vector<GTO> gtoss);
	const std::string orb() const;

	friend std::ostream& operator <<(std::ostream &os,const CGF &rhs);
};

#endif //_CGF_H
