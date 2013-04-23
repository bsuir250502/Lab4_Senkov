#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib1.h"

#define STR_MAX 256

int int_input(char *information, int min, int max, FILE *file);
void file_output(char *file_name);
void help(int argc, char **argv);

int main(int argc, char **argv)
{
    help(argc,argv);  
    return 0;
}

void help(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        file_output("README.txt");
        exit(0);
    }
}
