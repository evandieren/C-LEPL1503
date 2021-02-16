/*
Recreates the behaviour of the test method, used in the shell.
returns 0 if the expression given in the arguments of the function is true, 1 if false.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int eq(int a, int b){
    return !(a == b);
}

int ge(int a, int b){
    return !(a >= b);
}

int gt(int a, int b){
    return !(a > b);
}

int le(int a, int b){
    return !(a <= b);
}

int lt(int a, int b){
    return !(a < b);
}

int ne(int a, int b){
    return !(a != b);
}


int main (int argc,char**argv){
    if (argc == 4){
        char *argument = argv[2];
        int a = atoi(argv[1]);
        int b = atoi(argv[3]);
        if (strcmp(argument, "-eq") == 0) return eq(a,b);
        if (strcmp(argument, "-ge") == 0) return ge(a,b);
        if (strcmp(argument, "-gt") == 0) return gt(a,b);
        if (strcmp(argument, "-le") == 0) return le(a,b);
        if (strcmp(argument, "-lt") == 0) return lt(a,b);
        if (strcmp(argument, "-ne") == 0) return ne(a,b);
    }
    
    return 1;
}