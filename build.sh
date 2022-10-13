#!/usr/bin/env bash
if [[ "$#" -ne 0 && $1 == "debug" ]]
then
    mkdir -p build_debug;
    cd build_debug;
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..;
    # cmake -DCMAKE_BUILD_TYPE=Debug ..;
else
    mkdir -p build;
    cd build;
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..;
    # cmake -DCMAKE_BUILD_TYPE=Release ..;
fi
make;
cd ..;