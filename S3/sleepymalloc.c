/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */

#include <stdio.h>
#include <stdlib.h>

void *sleepy_malloc(size_t s) {
    int c = 0;
    while (c < 10){
        void * result = malloc(s);
        if (result == NULL){
            sleep(5);
        }else{
            return result;
        }
        c++;
    }
    return NULL;
}