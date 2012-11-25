/*
 * factorial.cpp
 *
 * calculate 'single' and double factorial
 *
 * Author: Ivo Filot
 *
 */

#include "factorial.h"

int fact(int n){
  if (n <= 1) return 1;
  return n*fact(n-1);
}

int fact2(int n){ /* double factorial function = 1*3*5*...*n */
  if (n <= 1) return 1;
  return n*fact2(n-2);
}
