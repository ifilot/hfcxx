# Overview

HFCXX is a Hartree-Fock code in C++. The program currently supports only single-point
calculations (i.e. no geometry optimizations). The basis sets STO-3G and STO-6G
are included for atoms up to N=8 (oxygen).

# Compiling source code
Simply type:
`./configure`
`make`

# Usage
./hfcxx <inputfile.in> > <outputfile>

Example:
`./hfcxx molecules/h2.in > h2.out`
