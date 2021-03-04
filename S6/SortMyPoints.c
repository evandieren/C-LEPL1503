/*
TO-DO
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct points {
    int NOMA;
    float LEPL1103;
    float LEPL1203;
    float LEPL1108;
    float LEPL1302;
    float LEPL1402;
    float average;
} points_t;

/*
* Function used to compare two structures based on their averages.
*
* @s1 : a pointer to the first structure
* @s2 : a pointer to the second structure
*
* @return an integer less than, equal to, or greater than zero if the first argument is considered to be
*        respectively less than, equal to, or greater than the second
*/
int compar(const void* s1, const void* s2){
    return (((points_t*) s1)->average - ((points_t*) s2)->average)*1000;
}

/*
* Function used to update the file with the structures stored in it
*
* @filename : the path indicating where to find the file (!= NULL)
*
* @return 0 if no error
*        -1 if open failed
*        -2 if mmap failed
*        -3 if munmap failed
*        -4 if msync failed
*        -5 if fstat failed
*        -6 if close failed
*/
int sort(char* filename){

    // Opens the file

    int fd = open(filename,O_RDWR);
    if (fd == -1){
        return -1;
    }

    // Takes info about the size of the file

    struct stat buf;

    if (fstat(fd,&buf) == -1){
        if (close(fd) < 0){
            return -6;
        } 
        return -5;
    }

    int size = buf.st_size;

    // Map to use the file as an array

    points_t * map = mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    if (map == MAP_FAILED){
        if (close(fd) < 0){
            return -6;
        } 
        return -2;
    }

    // Computing the average for each student

    for(int i =0 ; i < size/sizeof(points_t) ;i++) {
        map[i].average = (map[i].LEPL1103+map[i].LEPL1203 + map[i].LEPL1108 + map[i].LEPL1302 + map[i].LEPL1402)/5 ;
    }

    // Sorting the file with our 'compar' comparator

    qsort(map,size/sizeof(points_t),sizeof(points_t),compar);

    // Sync the array

    if (msync(map,size,MS_SYNC) == -1){
        if (munmap(map,size) == -1){
            return -3;
        }
        if (close(fd) < 0){
            return -6;
        }
        return -4;
    }

    // UnMapping the link between the memory and the file

    if (munmap(map, size) == -1 ) {
        if (close(fd) < 0){
            return -6;
        }
        return -3;
    }

    // Closes the file
    

    if(close(fd) < 0){
        return -6;
    }
    return 0 ;
}
