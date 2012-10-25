#ifndef _OVERLAP_H
#define _OVERLAP_H

#include "gto.h"
#include "cgf.h"
#include "func.h"

double cgf_overlap(CGF &cgf1, CGF &cgf2);
double gto_overlap(GTO &gto1, GTO &gto2);
double overlap_1D(unsigned int l1, unsigned int l2, double x1, double x2, double gamma);

#endif //_OVERLAP_H
