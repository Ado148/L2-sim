// Author: Bc. Adam Pap
// Description: This program is used to process the input files data and then 
//              give them to the python script

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    printf("ARGs number: %d\n", argc);
    while(argc != 0){
        printf("ARG: %s\n", *argv);
        argc--;
        argv++;
    }

    return 0;
}
