/*
Given a large array of integers, we write a function to edit the elements at a given index in the array 
and another function to retrieve a specific element from this array.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * @pre filename != NULL, index >= 0
 * @post return the integer at the index {index}
 *       of the array in the file {filename}.
 *       return -1 in case of error.
 *       return -2 if index >= length of array.
 */
int get(char *filename, int index) {
    int fd = open(filename,O_RDONLY);
    if (fd == -1){
        return -1;
    }

    // We use fstat to gather some information about the file we just opened

    struct stat buffer;

    if (fstat(fd,&buffer)){
        return -1;
    }  

    if (buffer.st_size < index){
        close(fd);
        return -2;
    }

    int * mapper = mmap(NULL,buffer.st_size,PROT_READ,MAP_SHARED,fd,0);

    if (mapper == MAP_FAILED){
        close(fd);
        return -1;
    }

    int result = mapper[index];

    if (close(fd) == -1){
        munmap((void*) mapper,buffer.st_size);
        return -1;
    }   

    if (munmap((void*) mapper,buffer.st_size)){
        return -1;
    }

    return result;
}

/*
 * @pre filename != NULL, index >= 0
 * @post set the element in the file {filename}
 *       at index {index} at value {value}.
 *       do nothing in case of errors
 */
void set(char *filename, int index, int value) {
    int fd = open(filename,O_RDWR);

    if (fd == -1){
        return;
    }

    // We use fstat to gather some information about the file we just opened

    struct stat buffer;

    if (fstat(fd,&buffer)){
        return;
    }  

    if (buffer.st_size < index){
        close(fd);
        return;
    }


    int * mapper = mmap(NULL,buffer.st_size,PROT_WRITE | PROT_READ,MAP_SHARED,fd,0);

    if (mapper == MAP_FAILED){
        close(fd);
        return;
    }

    mapper[index] = value;

    if (close(fd) == -1){
        munmap((void*) mapper,buffer.st_size);
        return;
    }   

    if (munmap((void*) mapper,buffer.st_size)){
        return;
    }
}