/*
le 4/03/2021, par jc

Question 1

*/
return(((int )(((points_t *)s1)->average*1000))-((int )(((points_t *)s2)->average*1000)));


/*


Question 2

*/


int file = open(filename, O_RDWR);
if(file==-1){return(-1);};
struct stat buffer;
int fs = fstat(file,&buffer);
if(fs==-1){
    close(file);
    return(-5);
}

size_t size =buffer.st_size;
int len = size/sizeof(points_t);
points_t *data = mmap (NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
if(data==MAP_FAILED){
    close(file);
    return(-2);
}
for(int i=0;i<len;i++){
    data[i].average = (data[i].LEPL1103+data[i].LEPL1203 + data[i].LEPL1108 + data[i].LEPL1302+data[i].LEPL1402)/5.0;
}

qsort(data, buffer.st_size/sizeof(points_t),sizeof(points_t),compar);
int sync = msync(data,len*sizeof(points_t),MS_SYNC);
if( sync == -1) {
    munmap(data, len*sizeof(points_t));
    close(file);
    return -4;
}
int mun= munmap(data, len*sizeof(points_t));
if (mun == -1 ) {
    close(file);
    return -3;
}
if(close(file) == -1 ){
    return -6;
}
return 0;
