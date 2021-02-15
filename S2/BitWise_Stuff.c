/*
All BitWise related exercices
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t get_3_leftmost_bits(uint32_t x) {
    return (uint8_t) (x >> 29);
}

uint8_t get_4_rightmost_bits(uint32_t x) {
    return (uint8_t) ((x << 28)>>28);
}

/*
 * @pre 0<= pos < 64
 */
uint64_t set_bit(uint64_t x, int pos, int value) {
    uint64_t one = 1 << (pos);
    if (value){
        return (x|one);
    }else{
        return (x & (~one));
    }
}

uint32_t cycle_bits(uint32_t x, uint8_t n) {
    return ((x<<n)|(x>>(32-n)));
}

uint32_t reset_highestorder_strong_bit(uint32_t x) {
    int pos = 0;
    for (int i = 1 ; i<=32 ; i++){
        if (x >> (32-i)){
            int one = (1<<(31-pos));
            return (x^(one));
        }
        pos++;
    }
    return x;
}

uint8_t nbits(uint32_t n) {
    uint8_t c = 0;
    for (int i = 0;i < 32;i++){
        if ((n >> (32-i)) == 1){
            c++;
            n = n - (1 << (32-i)); 
        }
    }
    return c;
}