#!/bin/bash

# Author:       Adam Pap
# Description:  This script will build and compile the project

# Check if the build directory exist
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

cmake ..

make install
