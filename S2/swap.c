/*
Exchanges the values pointed by i and j.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}