#!/bin/sh
cd build
cmake -Dtest=ON ..
make
make test
