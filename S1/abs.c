/*
Returns the absolute value of i
*/

#include <stdio.h>
#include <stdlib.h>

int absval(int i){
    if (i <= 0){
        return -i;
    }else{
        return i;
    }
}

/*
TEST
*/

int main(void){
	printf("%d\n",abs(-1)); // SHOULD PRINT 1
	printf("%d\n",abs(5)); // SHOULD PRINT 5
}