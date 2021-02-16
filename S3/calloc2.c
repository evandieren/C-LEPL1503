/* 
Returns a pointer to an array of nmemb elements which have been initialized to 0.
These elements each have a size of 'size'.
If nmemb = 0 or size = 0, then calloc2 returns NULL.
 */

#include <stdio.h>
#include <stdlib.h>


void *calloc2(size_t nmemb, size_t size){

    if ((nmemb == 0) | (size == 0)){return NULL;}
    size_t len = nmemb*size;
    void * ret = malloc(len);
    if (ret != NULL){
        for (int i = 0; i < len; ++i)
        {
            *((int*) ret + i) = 0;
        }
    }
    return ret;
}