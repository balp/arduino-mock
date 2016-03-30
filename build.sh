#!/bin/sh

[ ! -d build ] && mkdir build

cd build && \
cmake  -Dtest=ON .. && \
make VERBOSE=1 && \
ctest -VV
