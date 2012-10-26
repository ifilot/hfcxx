#include<iostream>
#include "vector.h"
#include "ludcmp.h"
#include "eigen.h"

int main() {

	int size = 3;

	MatDoub mat(size,size),ainv(size,size,0.0);

	/* column 0 */
	mat[0][0] = 1;
	mat[1][0] = 7;
	mat[2][0] = 3;
	/* column 1 */
	mat[0][1] = 7;
	mat[1][1] = 4;
	mat[2][1] = -5;
	/* column 2 */
	mat[0][2] = 3;
	mat[1][2] = -5;
	mat[2][2] = 6;

	std::cout << "regular matrix" << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << mat;
	std::cout << std::endl;

	/* output lu decomposition */
	std::cout << "lu decomposition of matrix" << std::endl;
	std::cout << "--------------" << std::endl;
	LUdcmp ludcmp(mat);
	std::cout << ludcmp.lud();
	std::cout << std::endl;

	/* output matrix determinant */
	std::cout << "matrix determinant: ";
	std::cout << ludcmp.det() << std::endl;
	std::cout << std::endl;

	/* calculate and output matrix inverse */
	std::cout << "inverse matrix" << std::endl;
	std::cout << "--------------" << std::endl;
	ludcmp.inverse(ainv);
	std::cout << ainv;
	std::cout << std::endl;

	/* calculate and output matrix inverse */
	std::cout << "diagonalization of matrix" << std::endl;
	std::cout << "-------------------------" << std::endl;
	Symmeig eig(mat,true);
	std::cout << eig.z;

	std::cout << "eigenvalues" << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << eig.d[0] << "\t" << eig.d[1] << "\t" << eig.d[2] << std::endl;

	return 0;
}
