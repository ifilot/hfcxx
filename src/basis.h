/*
 * basis.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: header file for basis (set) class
 */
 
#ifndef _BASIS_H
#define _BASIS_H

#include<string>
#include <stdlib.h>
#include "gto.h"
#include "vec3.h"

class Basis{
	private:
	std::vector<GTO> gtos;
	std::string basisset;

	public:
	Basis();
	Basis(std::string basisset);
	void set(std::string type, unsigned int z, Vec3 r);
	void setType(std::string basissett);
	std::vector<GTO> getGTOs() const;

	private:
	void addGTOs_sto3g(std::string type, unsigned int z, Vec3 r);
	void addGTOs_sto6g(std::string type, unsigned int z, Vec3 r);
	
	/* GTOs for sto-xg basis sets */
	void addGTO_s(double alpha, double c, Vec3 r);
	void addGTO_px(double alpha, double c, Vec3 r);
	void addGTO_py(double alpha, double c, Vec3 r);
	void addGTO_pz(double alpha, double c, Vec3 r);
	void addGTO_dx2(double alpha, double c, Vec3 r);
	void addGTO_dxy(double alpha, double c, Vec3 r);
	void addGTO_dxz(double alpha, double c, Vec3 r);
	void addGTO_dy2(double alpha, double c, Vec3 r);
	void addGTO_dyz(double alpha, double c, Vec3 r);
	void addGTO_dz2(double alpha, double c, Vec3 r);
};

#endif //_BASIS_H
