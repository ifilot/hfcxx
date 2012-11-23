/*
 *  matrix.h
 *
 *  Author: Ivo Filot
 *  Modified: 2012-08-28
 */

#ifndef _MATRIX_H
#define _MATRIX_H

#include<iostream>
#include<iomanip>

template <class T>
class Matrix {
private:
	int nn;		//number of rows
	int mm; 	//number of columns
	T **v;		//pointer to pointer of type T
public:
	Matrix();																					// Default constructor
	Matrix(int n, int m);															// Construct m x n matrix with value zero
	Matrix(int n, int m, const T &a);									// Construct m x n matrix with value a
	Matrix(int n, int m, const T *a);									// Construct m x n array using array a
	Matrix(const Matrix &rhs);												// Copy constructor

	Matrix & operator=(const Matrix &rhs);						// Assignment operator

	typedef T value_type; 														// Make T available externally
	T* operator[](const int i);								// Subscripting: pointer to row i
	const T* operator[](const int i) const;

	unsigned int nrows() const;													// Get number of rows
	unsigned int ncols() const;													// Get number of columns
	void resize(const int newn, const int newm); 			// resize (contents not preserved)
	void assign(const int newn, const int newm, const T &a); 			// resize and assign a constant value

	void rowswap(const int r1, const int r2);											// swap two rows
	void columnswap(const int r1, const int r2);											// swap two columns

	template <class U>
	friend std::ostream& operator <<(std::ostream &os,const Matrix<U> &rhs);	//output matrix

	~Matrix();																				// deconstructor
};

/* TYPEDEFS */

typedef Matrix<double> MatDoub;
typedef Matrix<double> Hmatrix;
typedef Matrix<double> Tmatrix;
typedef Matrix<double> Vmatrix;
typedef Matrix<double> Smatrix;
typedef Matrix<double> Xmatrix;
typedef Matrix<double> Fmatrix;

#include "matrix.cpp"

#endif // _MATRIX_H
