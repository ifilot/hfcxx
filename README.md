# HFCXX

## Overview

HFCXX is a Hartree-Fock code in C++. The program currently supports only
single-point calculations (i.e. no geometry optimizations). The basis 
sets STO-3G and STO-6G are included for atoms up to N=8 (oxygen). 
This program is mainly made for educational purposes.

:new: Interested in learning Density Functional Theory?
Have a look at [DFTCXX](https://github.com/ifilot/dftcxx)!

## Compilation

```
mkdir build && cd build
cmake ../src
make -j9
```

## Usage

For example:
  `./hfcxx molecules/h2.in > h2.out`

## Contributing

1. Fork it.
2. Create a branch (`git checkout -b my_markup`)
3. Commit your changes (`git commit -am "Added Snarkdown"`)
4. Push to the branch (`git push origin my_markup`)
5. Open a [Pull Request][1]
6. Enjoy a refreshing beer and wait
