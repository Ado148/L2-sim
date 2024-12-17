#!/bin/bash

# Author:       Bc. Adam Pap
# Description:  This script will parse names of the files in the current dir

set -o pipefail  # If any command in the pipe fails, the pipeline fails

files_arr=() # arr for holding the names of the files

if [ "$#" -lt 1 ]; then 
    echo "No file names to be proccessed."
    exit 1
fi

# loop through all the arguments
for file in "$@"; do
    files_arr+=("$file")
done 

# run the c++ and python program
./build/main "${files_arr[@]}" | python3.10 ./src/flat_drawer.py

# Check if the pipeline failed
if [ $? -ne 0 ]; then
    echo "Error occured while running the program"
    exit 1
fi

exit 0