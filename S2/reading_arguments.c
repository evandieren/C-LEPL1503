/*
Prints out every 2 arguments, starting from the first one.

  Example : 

./myProg a b c d e f g

should return in the terminal :

a c e g

*/

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char**argv){

    for (int i = 1; i < argc; i = i+2){
        if (i!=1){
            printf(" ");
        }
        printf("%s",argv[i]);
    }
    printf("\n");
    return 0;
}