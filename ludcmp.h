/*
 * ludcmp.h
 *
 * Author: Ivo Filot
 * Modified: 2012-08-30
 *
 * Description: Header file for performing LU decomposition on
 * a matrix.
 *
 * Notes:
 * stdlib.h is included for the abs function
 *
 */

#ifndef _LUDCMP_H
#define _LUDCMP_H

#include<iostream>
#include<stdlib.h>
#include "matrix.h"
#include "vector.h"

class LUdcmp{
	private:
	unsigned int n;
	MatDoub lu;		//stores the decomposition
	VecInt indx;	//stores the permutation
	double d;			//used by determinant
	MatDoub &aref;  //used by mprove to store original matrix

	public:
	LUdcmp(MatDoub &a);	//constructor, takes matrix as argument
	void inverse(MatDoub &ainv);	//calculates matrix inverse
	void solve(VecDoub &b, VecDoub &x);
	void solve(MatDoub &b, MatDoub &x);
	double det();	//calculates determinant
	MatDoub lud();  //return LU decomposited matrix
	void mprove(VecDoub &b, VecDoub &x);
};

#endif //_LUDCMP_H
