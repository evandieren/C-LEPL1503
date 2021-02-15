#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
print to stdout "The magic number is NUMBER.\n"
 */
void print_digit(int number) {
    printf("The magic number is %d.\n", number);
}

/*
print to stdout "foo"
*/

void print_foo() {
    printf("%s\n", "foo");
}


/* 
 * format_str, example:
 * format_str(buf, 42, "Olivier", 'B') will write into buf
 * the string "Mister Olivier B. has 42 eggs" (no line feed)
 * The given buffer is guaranteed to be big enough
 */
void format_str(char *buffer, unsigned int d, char *name, char initial) {
    sprintf(buffer,"Mister %s %c. has %d eggs", name, initial, d);
}