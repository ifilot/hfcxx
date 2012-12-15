/*
 * factorial.h
 *
 * calculate 'single' and double factorial
 *
 * Author: Ivo Filot
 *
 */

#ifndef _FACTORIAL_H
#define _FACTORIAL_H

inline int fact(int n){
  return n <= 1 ? 1 : n*fact(n-1);
}

inline int fact2(int n){ /* double factorial function = 1*3*5*...*n */
  return n <= 1 ? 1 : n*fact2(n-2);
}

#endif //_FACTORIAL_H
