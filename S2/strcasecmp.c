/*
Returns -1,0,1 if s1 is found, respectively, to be less than, to match, or be greater than s2, 
ignoring the cases of the characters.
*/

#include <stdio.h>
#include <stdlib.h>


int strcasecmp(const char *s1, const char *s2) {

    size_t i = 0;

    while ((*(s1 + i) != '\0') && (*(s2 + i) != '\0')){
        int a = *(s1+i), b = *(s2+i);

        // I have to use this trick because we don't have any access to the string.h library

        if (a > 90){
            a = a - 32;
        }
        if (b > 90){
            b = b - 32;
        }

        if (a > b){
            return 1;
        }
        if (a < b){
            return -1;
        }

        i++;
    }

    if ((*(s1 + i) == '\0') && (*(s2 + i)== '\0')){
        return 0;
    }else{
        if (*(s1 + i) == '\0'){
            return -1;
        }else{
            return 1;
        }
    }

}