/*
Returns a buffer that has the same size as src, and copies the content of src to this buffer.
*/

#include <stdio.h>
#include <stdlib.h>

char *buf_strcpy(const char *src){
    size_t len = strlen(src);
    char * dest = (char*) malloc(sizeof(char)*(len+1));
    if (dest != NULL){
        for (int i = 0; i <= len; i++){
            *(dest + i) = *(src + i);
        }
    }
    return dest;
}