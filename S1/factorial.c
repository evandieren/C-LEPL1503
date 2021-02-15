/*
Returns the factorial of n
*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if (n == 0){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

/*
TEST
*/

int main(void){
    printf("%d\n",factorial(5)); // SHOULD PRINT 120
}