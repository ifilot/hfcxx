/**************************************************************************
 *   eispack.h  --  This file is part of HFCXX.                           *
 *                                                                        *
 *   Copyright (C) 2012, Ivo Filot                                        *
 *                                                                        *
 *   HFCXX is free software:                                              *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   HFCXX is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/
 
#ifndef _EISPACK_H
#define _EISPACK_H

int bakvec ( int n, double t[], double e[], int m, double z[] );
void cbabk2 ( int n, int low, int igh, double scale[], int m, double zr[], 
  double zi[] );
void bandr ( int n, int mb, double a[], double d[], double e[], double e2[], 
  int matz, double z[] );
void csroot ( double xr, double xi, double &yr, double &yi );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
double pythag ( double a, double b );
double r8_abs ( double x );
double r8_epsilon ( );
double r8_max ( double x, double y );
double r8_min ( double x, double y );
double r8_sign ( double x );
void r8mat_identity  ( int n, double a[] );
double *r8mat_mm_new ( int n1, int n2, int n3, double a[], double b[] );
void r8mat_print ( int m, int n, double a[], std::string title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, std::string title );
double *r8mat_uniform_01_new ( int m, int n, int &seed );
void r8vec_print ( int n, double a[], std::string title );
int rs ( int n, double a[], double w[], int matz, double z[] );
int rsb ( int n, int mb, double a[], double w[], int matz, double z[] );
void timestamp ( );
int tql2 ( int n, double d[], double e[], double z[] );
int tqlrat ( int n, double w[], double fv2[] );
void tred1 ( int n, double a[], double w[], double fv1[], double fv2[] );
void tred2 ( int n, double a[], double d[], double e[], double z[] );

#endif //_EISPACK_H
