/*
 * matfunc.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: Matrix operations
 */
 
#ifndef _MATPROD_H
#define _MATPROD_H

#include "matrix.h"

MatDoub matprod(MatDoub &a, MatDoub &b);
MatDoub matsum(MatDoub &a, MatDoub &b);
MatDoub trimatprod(MatDoub &a, MatDoub &b, MatDoub &c);

#endif //_MATPROD_H
