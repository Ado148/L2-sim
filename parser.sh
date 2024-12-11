#!/bin/bash

# Author: Bc. Adam Pap
# Description: This script will parse names of the files in the current dir

files_arr=() # arr for holding the names of the files

if [ "$#" -lt 1 ]; then 
    echo "No file names to be proccessed."
    exit 1
fi

# loop through all the arguments
for file in "$@"; do
    if [ ! -f "$file" ]; then
        echo "File $file does not exist."
        exit 1
    fi

    files_arr+=("$file")
done 

# run the c++ program
./build/main "${files_arr[@]}"
if [ $? -ne 0 ]; then
    echo "Error running C++ program"
    exit 1
fi

exit 0

# TODO - python, with | ?