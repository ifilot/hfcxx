hfcxx
=====

HFCXX is a Hartree-Fock code in C++. The program currently supports only single-point
calculatios (i.e. no geometry optimizations). The basis sets STO-3G and STO-6G
are included for atoms up to N=8 (oxygen).

Usage:
./hfcxx <inputfile.in> > <outputfile>
hfcxx.exe <inputfile.in> > <outputfile>

Example:
./hfcxx molecules/h2.in > h2.out
