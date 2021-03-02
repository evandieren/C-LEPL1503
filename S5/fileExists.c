/*
Checks if a file exists
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * @pre filename != NULL
 * @post return 0 if the file {filename} exist. -1 Otherwise.
 */
 int file_exists(char *filename){
    int file = open(filename,O_RDONLY); 
    if(file == -1) {
        return -1;
    }
    close(file);
    return 0;
 }