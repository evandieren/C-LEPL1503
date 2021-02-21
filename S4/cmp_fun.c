/*
Compares two functions given as arguments and return 1 if equivalent, 0 if not
(We will compare the output for the same inputs (0 to 255) uint8_t)
*/

/* HOW POINTERS TO FUNCTIONS WORKS :

int sum(int, int);
int (*s)(int, int);
s = sum;

*/

#include <stdio.h>
#include <stdlib.h>

int cmp_func(uint8_t (*fp1)(uint8_t), uint8_t (*fp2)(uint8_t)){
    for (int i = 0; i < 256; i++){
        if (fp1(i) != fp2(i)){
            return 0;
        }
    }
    return 1;
}

