#!/bin/bash

# Author:       Adam Pap
# Description:  This script will parse names of the files in the current dir

set -o pipefail  # If any command in the pipe fails, the pipeline fails

SCRIPT_DIR=$(dirname $(realpath "$0")) # determine the absolute path to the dir where the parser.sh is located

files_arr=() # arr for holding the names of the files

if [ "$#" -lt 1 ]; then 
    echo "Error: no file names to be proccessed"
    exit 1
fi

# loop through all the arguments
for file in "$@"; do
    file_path="${SCRIPT_DIR}/${file}"  # make the path relative to SCRIPT_DIR
    files_arr+=("$file_path")
done 

# determine location of the parser.sh
if [ -f "${SCRIPT_DIR}/../build/main" ]; then
    # we are in the dev dir
    MAIN_EXEC="${SCRIPT_DIR}/../build/main"
elif [ -f "${SCRIPT_DIR}/../bin/main" ]; then
    # we are in the install dir
    MAIN_EXEC="${SCRIPT_DIR}/../bin/main"
else
    echo "Error: main script not found"
    exit 1
fi

# run the c++ and python program
"$MAIN_EXEC" "${files_arr[@]}" | 
python3.10 "${SCRIPT_DIR}/flat_drawer.py"

# Check if the pipeline failed
if [ $? -ne 0 ]; then
    echo "Error occured while running the program"
    exit 1
fi

exit 0