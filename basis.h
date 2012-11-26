#ifndef _BASIS_H
#define _BASIS_H

#include<string>
#include "gto.h"
#include "vector.h"

class Basis{
	private:
	std::vector<GTO> gtos;

	public:
	Basis();
	void set(std::string type, unsigned int z, Vector3 r);
	std::vector<GTO> getGTOs() const;

	private:
	void addGTOs_sto3g(std::string type, unsigned int z, Vector3 r);
	void addGTO_s(double alpha, double c, Vector3 r);
	void addGTO_px(double alpha, double c, Vector3 r);
	void addGTO_py(double alpha, double c, Vector3 r);
	void addGTO_pz(double alpha, double c, Vector3 r);
	void addGTO_dx2(double alpha, double c, Vector3 r);
	void addGTO_dxy(double alpha, double c, Vector3 r);
	void addGTO_dxz(double alpha, double c, Vector3 r);
	void addGTO_dy2(double alpha, double c, Vector3 r);
	void addGTO_dyz(double alpha, double c, Vector3 r);
	void addGTO_dz2(double alpha, double c, Vector3 r);
};

#endif //_BASIS_H
