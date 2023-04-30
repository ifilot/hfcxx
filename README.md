# HFCXX

[![Build](https://github.com/ifilot/hfcxx/actions/workflows/build.yml/badge.svg)](https://github.com/ifilot/hfcxx/actions/workflows/build.yml)

## Overview

HFCXX is a Hartree-Fock code in C++. The program currently supports only
single-point calculations (i.e. no geometry optimizations). The basis 
sets STO-3G and STO-6G are included for atoms up to N=8 (oxygen). 

> **Note**: This program is mainly made for educational purposes. There are some
> (obvious) things to improve as suggested by others (e.g. loading of basis
> set coefficients from external files). My aim is however to keep this code
> simple and not use too many additional features.

* Interested in learning Density Functional Theory? Have a look at
  [DFTCXX](https://github.com/ifilot/dftcxx).
* Want to know more about electronic structure calculations, have a look at my
  [free lecture book](https://ifilot.pages.tue.nl/elements-of-electronic-structure-theory/).

## Compilation

```
mkdir build && cd build
cmake ../src
make -j9
```

## Usage

```
./hfcxx _input_file_ > _output_file_
```

For example, to run a HF calculation for H2, run

```
./hfcxx molecules/h2.in > h2.out
```
