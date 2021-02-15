/*
Returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pal(char *str) {
    if (str == NULL){return -1;}
    int len = strlen(str);
    if (len == 0){return 1;}

    int left = 0;
    int right = len - 1; // Index du dernier élément

    while (left < right){
        char str_left = str[left];
        char str_right = str[right];
        if (str_left == ' '){
            left++;
        }else if (str_right == ' '){
            right--;
        }else if (str_right != str_left){
            return 0;
        }else{
            left++;
            right--;
        }
    }
    return 1;
}