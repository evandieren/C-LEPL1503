/*
Creates / overwrite a file 'filename' with the array of size 'size'
which elements are of type 'point_t'.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
    int z;
} point_t;

/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename) {
    int file;
    int size_f = size*sizeof(point_t);

    // Crée ou ouvre le fichier

    if ((file = open (filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR)) < 0) {
        return -1;
    }

    // Alloue l'espace nécessaire (Supprime ou ajoute de l'espace) sur le fichier pointé par filename

    if(ftruncate(file,size_f)){
        return -6;
    }

    // Mapper

    void* mapper = mmap(NULL,size_f, PROT_WRITE | PROT_READ, MAP_SHARED, file, 0);

    if(mapper == (void*) (-1)){
        return -3;
    }

    // Copying and sync the result

    int result;
    memcpy(mapper,(void*) pt,size_f);
    result = msync(mapper,size_f,MS_SYNC);

    if (result == -1){
        munmap(mapper,size_f);
        return -5;
    }

    // On ferme tout et on désalloue la mémoire

    if(close(file) == -1){
        munmap(mapper,size_f);
        return -2;
    }

    result = munmap(mapper,size_f);
    if (result == -1){
        return -4;
    }
    return 0;
}