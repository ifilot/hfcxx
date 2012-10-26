#include<iostream>
#include "vector.h"
#include "ludcmp.h"
#include "eigen.h"

int main() {

	int size = 5;

	MatDoub mat(size,size),ainv(size,size,0.0);

	/* row 0 */
	mat[0][0] = 5;
	mat[1][0] = 2;
	mat[4][0] = -2;
	/* row 1 */
	mat[1][1] = 1;
	mat[2][1] = 4;
	mat[3][1] = 3;
	mat[4][1] = 2;
	/* row 2 */
	mat[2][2] = 2;
	mat[3][2] = 6;
	mat[4][2] = 3;
	/* row 3 */
	mat[2][3] = 3;
	mat[3][3] = 4;
	mat[4][3] = 1;
	/* row 4 */
	mat[4][4] = 2;

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

	return 0;
}
