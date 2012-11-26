/*
 * cgf.h
 *
 * defines contracted gaussian function class
 *
 * Author: Ivo Filot
 *
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
	CGF(const std::string type, const Vector3 rr);
	CGF(const std::string typee, const unsigned int z, const Vector3 rr);
	const std::string orb() const;

	friend std::ostream& operator <<(std::ostream &os,const CGF &rhs);

	private:
	void addGTOs_sto3g(std::string type, unsigned int z);
	void addGTO_s(double alpha, double c);
	void addGTO_px(double alpha, double c);
	void addGTO_py(double alpha, double c);
	void addGTO_pz(double alpha, double c);
	void addGTO_dx2(double alpha, double c);
	void addGTO_dxy(double alpha, double c);
	void addGTO_dxz(double alpha, double c);
	void addGTO_dy2(double alpha, double c);
	void addGTO_dyz(double alpha, double c);
	void addGTO_dz2(double alpha, double c);
};

#endif //_CGF_H
