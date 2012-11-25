/*
 *	matrix.cpp
 *
 *	Author: Ivo Filot
 *	Modified: 2012-08-28
 *
 *	Note because below are implementations of template member functions, this file
 *  is included in matrix.h. In principle, the pre-compiler merges this file
 *  together with the header file, but for convenience, the declaration and
 *  implementation are seperated (although for the compiler not).
 */

/*
 * default constructor, create 0x0 matrix object
 */
template <class T>
Matrix<T>::Matrix() : nn(0), mm(0), v(NULL) {}

/*
 *	alternative constructor, create m x n matrix object
 *
 *  1: initialize number of rows and columns to n and m respectively
 *	2: set v as an array of size n of pointers to type T
 *	3: calculate number of elements
 *	4: let v[0] (a pointer to type T) point to the first element of a new array with the size of the number of elements
 *	5: let each v[i] point to the address of v[i-1] incremented by the column size
 */
template <class T>
Matrix<T>::Matrix(int n, int m) : nn(n), mm(m), v(n>0 ? new T*[n] : NULL)
{
	int i,nel=m*n; // set number of elements
	if (v) v[0] = nel>0 ? new T[nel] : NULL;
	for (i=1;i<n;i++) v[i] = v[i-1] + m;
}

/*
 *	construct an n x m matrix where each element is initialized to value a
 */
template <class T>
Matrix<T>::Matrix(int n, int m, const T &a) : nn(n), mm(m), v(n>0 ? new T*[n] : NULL)
{
	int i,j,nel=m*n;
	if (v) v[0] = nel>0 ? new T[nel] : NULL;
	for (i=1; i< n; i++) v[i] = v[i-1] + m;
	for (i=0; i< n; i++) for (j=0; j<m; j++) v[i][j] = a;
}

/*
 *	construct an m x n matrix where each row is initialized to the array where a points to
 */
template <class T>
Matrix<T>::Matrix(int n, int m, const T *a) : nn(n), mm(m), v(n>0 ? new T*[n] : NULL)
{
	int i,j,nel=m*n;
	if (v) v[0] = nel>0 ? new T[nel] : NULL;
	for (i=1; i< n; i++) v[i] = v[i-1] + m;
	for (i=0; i< n; i++) for (j=0; j<m; j++) v[i][j] = *a++;
}

/*
 *	copy constructor
 */
template <class T>
Matrix<T>::Matrix(const Matrix &rhs) : nn(rhs.nn), mm(rhs.mm), v(nn>0 ? new T*[nn] : NULL)
{
	int i,j,nel=mm*nn;
	if (v) v[0] = nel>0 ? new T[nel] : NULL;
	for (i=1; i< nn; i++) v[i] = v[i-1] + mm;
	for (i=0; i< nn; i++) for (j=0; j<mm; j++) v[i][j] = rhs[i][j];
}

/*
 *	assignment operator
 */
template <class T>
Matrix<T> & Matrix<T>::operator=(const Matrix<T> &rhs)
{
	if (this != &rhs) {
		int i,j,nel;
		if (nn != rhs.nn || mm != rhs.mm) {
			if (v != NULL) {
				delete[] (v[0]);
				delete[] (v);
			}
			nn=rhs.nn;
			mm=rhs.mm;
			v = nn>0 ? new T*[nn] : NULL;
			nel = mm*nn;
			if (v) v[0] = nel>0 ? new T[nel] : NULL;
			for (i=1; i< nn; i++) v[i] = v[i-1] + mm;
		}
		for (i=0; i< nn; i++) for (j=0; j<mm; j++) v[i][j] = rhs[i][j];
	}
	return *this;
}

template <class T>
T* Matrix<T>::operator[](const int i)
{
#ifdef _CHECKBOUNDS_
if (i<0 || i>=nn) {
	throw("Matrix subscript out of bounds");
}
#endif
	return v[i];
}

template <class T>
const T* Matrix<T>::operator[](const int i) const
{
#ifdef _CHECKBOUNDS_
if (i<0 || i>=nn) {
	throw("Matrix subscript out of bounds");
}
#endif
	return v[i];
}

/*
 *	return the number of rows
 */
template <class T>
unsigned int Matrix<T>::nrows() const
{
	return nn;
}

/*
 *	return the number of columns
 */
template <class T>
unsigned int Matrix<T>::ncols() const
{
	return mm;
}

/*
 *	resize the matrix
 */
template <class T>
void Matrix<T>::resize(const int newn, const int newm)
{
	int i,nel;
	if (newn != nn || newm != mm) {
		if (v != NULL) {
			delete[] (v[0]);
			delete[] (v);
		}
		nn = newn;
		mm = newm;
		v = nn>0 ? new T*[nn] : NULL;
		nel = mm*nn;
		if (v) v[0] = nel>0 ? new T[nel] : NULL;
		for (i=1; i< nn; i++) v[i] = v[i-1] + mm;
	}
}

/*
 *	assign a new value for each element in the array
 */
template <class T>
void Matrix<T>::assign(const int newn, const int newm, const T& a)
{
	int i,j,nel;
	if (newn != nn || newm != mm) {
		if (v != NULL) {
			delete[] (v[0]);
			delete[] (v);
		}
		nn = newn;
		mm = newm;
		v = nn>0 ? new T*[nn] : NULL;
		nel = mm*nn;
		if (v) v[0] = nel>0 ? new T[nel] : NULL;
		for (i=1; i< nn; i++) v[i] = v[i-1] + mm;
	}
	for (i=0; i< nn; i++) for (j=0; j<mm; j++) v[i][j] = a;
}

template <class T>
void Matrix<T>::rowswap(const int r1, const int r2) {
	if(r1 < 0 || r2 < 0 || r1 >= nn || r2 >= nn) {
		throw("Row size exceeded in rowswap function");
	}
	for(int i=0; i<mm;i++) {
		std::swap(v[r1][i],v[r2][i]);
	}
}

template <class T>
void Matrix<T>::columnswap(const int r1, const int r2) {
	if(r1 < 0 || r2 < 0 || r1 >= mm || r2 >= mm) {
		throw("Column size exceeded in columnswap function");
	}
	for(int i=0; i<nn;i++) {
		std::swap(v[i][r1],v[i][r2]);
	}
}

template <class U>
std::ostream& operator<<(std::ostream &os,const Matrix<U> &rhs) {
	for(int i=0; i < rhs.nn; i++) {
			os << std::setw(10) << std::setiosflags(std::ios::right);
			os << std::setprecision(5) << std::setiosflags(std::ios::fixed);
		for(int j=0; j < rhs.mm; j++) {
			os << rhs[i][j] << "\t";
		}
		os << std::endl;
	}
	return os;
}

/*
 *	deconstructor
 */
template <class T>
Matrix<T>::~Matrix()
{
	if (v != NULL) {
		delete[] (v[0]);
		delete[] (v);
	}
}
