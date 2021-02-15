/*
Returns the length of s
*/

#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char* s) {
    int length = 0;
    while *(s+length) != '\0'{
        length++;
    }
    return length;
}

/*
Version sans pointeurs
*/

/*
size_t strlen(const char* s) {
    int length = 0;
    while s[length] != '\0'{
        length++;
    }
    return length;
}
*/
