#include "basis.h"

Basis::Basis() {};

void Basis::set(std::string type, unsigned int z, Vector3 r) {
	gtos.empty();
	addGTOs_sto3g(type, z, r);
};

std::vector<GTO> Basis::getGTOs() const{
	return gtos;
}

	void Basis::addGTO_s(double alpha, double c, Vector3 r) {
  	gtos.push_back(GTO(c, r, alpha, 0,0,0));
	}

	void Basis::addGTO_px(double alpha, double c, Vector3 r) {
	 gtos.push_back(GTO(c, r, alpha, 1,0,0));
	}

	void Basis::addGTO_py(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 0,1,0));
	}

	void Basis::addGTO_pz(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 0,0,1));
	}

	void Basis::addGTO_dx2(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 2,0,0));
	}

	void Basis::addGTO_dxy(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 1,1,0));
	}

	void Basis::addGTO_dxz(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 1,0,1));
	}

	void Basis::addGTO_dy2(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 0,2,0));
	}

	void Basis::addGTO_dyz(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 0,1,1));
	}

	void Basis::addGTO_dz2(double alpha, double c, Vector3 r) {
 	 gtos.push_back(GTO(c, r, alpha, 0,0,2));
	}

#include "basis-sto3g.cpp"
