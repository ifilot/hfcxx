/*
 * kinetic.h
 *
 * hfcxx package <https://github.com/ifilot/hfcxx>
 *
 * Author: Ivo Filot <ivo@zuidstijl.nl>
 * Description: Kinetic energy integrals
 */
 
#ifndef _KINETIC_H
#define _KINETIC_H

#include "gto.h"
#include "cgf.h"
#include "overlap.h"

double cgf_kinetic(CGF &cgf1, CGF &cgf2);
double gto_kinetic(GTO &gto1, GTO &gto2);

#endif
