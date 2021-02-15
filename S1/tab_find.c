/* 
@tab : an array of int
@len : the number of int in tab
@elem : the elem looked for
@return : return the index at which elem is found, else returns -1 if not found. 
*/

#include <stdio.h>
#include <stdlib.h>

int tab_find(int tab[], int len, int elem){
    for (int i = 0; i < len;i++){
        if (tab[i] == elem){
            return i;
        }
    }
    return -1;
}

/*
TEST
*/

int main(void){
    int num[5] = {1, 2, 3, 4, 5};
    printf("%d\n",tab_find(num,4,3)); // SHOULD PRINT 2
    printf("%d\n",tab_find(num,4,6)); // SHOULD PRINT -1
}