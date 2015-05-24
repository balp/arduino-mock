#!/bin/sh
set -eu

cd -- "$(dirname -- "$0")"
cmake -Dtest=ON ..
make
ctest -V
