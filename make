#!/bin/sh
mkdir -p build
cd build || exit
cmake .. -G Ninja
cmake --build .
./bin/morpho
