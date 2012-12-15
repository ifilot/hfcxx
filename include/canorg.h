/*
 * canorg.h
 *
 * routine for canonical orthogonalization of matrix
 *
 * Author: Ivo Filot
 *
 */

#ifndef _CANORG_H
#define _CANORG_H

#include "matrix.h"
#include "matfunc.h"
#include "eigsym.h"

Xmatrix canorg(const Smatrix &S);
MatDoub transpose(MatDoub &a);

#endif //_CANORG_H
