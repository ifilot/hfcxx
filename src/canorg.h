/*
 * canorg.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: routine for canonical orthogonalization of matrix
 */

#ifndef _CANORG_H
#define _CANORG_H

#include "matrix.h"
#include "matfunc.h"
#include "eigsym.h"

Xmatrix canorg(const Smatrix &S);
MatDoub transpose(MatDoub &a);

#endif //_CANORG_H
