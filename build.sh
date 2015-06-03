#!/bin/sh

[ ! -d build ] && mkdir build
[ -e build/external-project-utils.cmake ] && rm build/external-project-utils.cmake

cd build && \
wget https://raw.githubusercontent.com/octoblu/cmake-external-project-utils/master/external-project-utils.cmake && \
cmake  .. && \
make VERBOSE=1 && \
ctest -VV
