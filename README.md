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

### Linux

Ensure you have all the required packages installed

```
sudo apt install build-essential cmake libcppunit-dev
```

```
mkdir build && cd build
cmake ../src
make -j9
```

### For Apple Silicon

Install the compilation toolchain via [brew](https://brew.sh/).

```
brew install make gcc cmake cppunit
```

You also have to make sure that you have xCode installed

```
xcode-select --install
```

Packages are located in a different folder compared to linux

```
mkdir build && cd build
cmake -DCMAKE_CXX_FLAGS="-I/opt/homebrew/opt/cppunit/include" ../src
make -j9
```
## Testing

After compilation, you can test the `hfccc` executable by running the 
test suite.

> **Note**: The testsuite contains a HF calculation of benzene using the
> STO-6g basis set. Since HFCXX is not optimized for speed, running the
> tests can take a few minutes to complete.

```
make test
```

A successful test should give an output similar to the following

```
Running tests...
Test project /mnt/d/PROGRAMMING/CPP/hfcxx/build
    Start 1: TestMolecules
1/1 Test #1: TestMolecules ....................   Passed   50.70 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =  50.72 sec
```

## Usage

```
./hfcxx _input_file_ > _output_file_
```

For example, to run a HF calculation for H2, run

```
./hfcxx molecules/h2.in > h2.out
```
