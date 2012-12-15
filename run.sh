#!/bin/bash

# This program runs a series of examples provided in the
# examples directory

echo -n "H2...  "
bin/hfcxx examples/h2.in > examples/h2.out
echo "[DONE]"

echo -n "NH3... "
bin/hfcxx examples/nh3.in > examples/nh3.out
echo "[DONE]"

echo -n "CH4... "
bin/hfcxx examples/ch4.in > examples/ch4.out
echo "[DONE]"

echo -n "H2O... "
bin/hfcxx examples/h2o.in > examples/h2o.out
echo "[DONE]"
