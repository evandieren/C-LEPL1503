/*
Reads integers in a binary file
*/


#include <stdio.h>
#include <stdlib.h>

/*
 * @pre filename != NULL, name of the file
 * @post returns the sum of all integers stored in the binary file.
 *       return -1 if the file can not be open.
 *       return -2 if the file can not be closed.
 *       return -3 if mmap() fails.
 *       return -4 if munmap() fails.
 *       return -5 if fstat() fails.
 */
int sum_file(char *filename) {
    int file = open(filename, O_RDONLY);
    if (file == -1){
        return -1;
    }

    // We use fstat to gather some information about the file we just opened

    struct stat buffer;

    if (fstat(file,&buffer)){
        return -5;
    }  

    if (buffer.st_size == 0){
        close(file);
        return 0;
    }

    // We use mmap to gather the information from file to mapper.

    int result = 0;

    int * mapper = mmap(NULL,buffer.st_size,PROT_READ,MAP_SHARED,file,0);

    if (mapper == MAP_FAILED){
        close(file);
        return -3;
    }

    for (int i = 0; i < (buffer.st_size / sizeof(int)); ++i)
    {
        result += *(mapper + i);
    }

    if (close(file) == -1){
        munmap((void*) mapper,buffer.st_size);
        return -2;
    }

    if (munmap((void*) mapper,buffer.st_size)){
        return -4;
    }
    return result;
}
