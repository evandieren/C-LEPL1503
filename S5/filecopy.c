/*
Copies the file given in arguments.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * @pre file_name != NULL, name of the original file
 *      new_file_name != NULL, name of the new file (the copy)
 *
 * @post copy the contents of {file_name} to {new_file_name}.
 *       return 0 if the function terminates with success, -1 in case of errors.
 */
int copy(char *file_name, char *new_file_name) {
        
    int source = open(file_name, O_RDWR);
    if (source == -1){
        return -1;
    }

    struct stat buffer_src;

    if (fstat(source,&buffer_src) == -1){
        return -1;
    }

    mode_t permissions = buffer_src.st_mode;

    int size = buffer_src.st_size;

    int dest = open(new_file_name,O_RDWR | O_CREAT | O_TRUNC,permissions);
    if (dest == -1){
        return -1;
    }

    if(ftruncate(dest,size)){
        return -1;
    }

    void* mapper_src = mmap(NULL,size, PROT_READ, MAP_SHARED, source, 0);

    if(mapper_src == MAP_FAILED){
        return -1;
    }

    void* mapper_dest = mmap(NULL,size, PROT_WRITE, MAP_SHARED, dest, 0);

    if(mapper_dest == MAP_FAILED){
        munmap(mapper_src,size);
        return -1;
    }

    memcpy(mapper_dest,mapper_src,size);

    int result = msync(mapper_dest,size,MS_SYNC);

    if (result == -1){
        munmap(mapper_dest,size);
        munmap(mapper_src,size);
        return -1;
    }

    if((close(source) == -1) | (close(dest) == -1)){
        munmap(mapper_src,size);
        munmap(mapper_dest,size);
        return -1;
    }

    result = munmap(mapper_dest,size);
    if (result == -1){
        return -1;
    }
    return 0;


}