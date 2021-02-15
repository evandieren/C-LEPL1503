/*
strcat concatenates the strings dest and src in the dest pointer
*/

#include <stdio.h>
#include <stdlib.h>

char* strcat(char* dest, const char* src) {
    // Finding the length of dest because we can't access the string.h library
    size_t dest_len = 0;
    while (dest[dest_len] != '\0'){
        dest_len++;
    }

    size_t i = 0;
    while (src[i] != '\0'){
        dest[dest_len + i] = *(src + i);
        i++; 
    }
    dest[dest_len+i] = '\0';

    return dest;
}