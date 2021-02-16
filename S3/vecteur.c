#include <stdio.h>
#include <stdlib.h>

struct vector_t {
  int size;
  float *v;
};

// initialise le vecteur à la valeur du réel
struct vector_t * init(int size, float v){
    struct vector_t * vector = (struct vector_t *) malloc(sizeof(struct vector_t));

    if (vector == NULL){return NULL;}
    vector->size = size;

    vector->v = (float *) malloc(sizeof(float)*size);

    if (vector->v == NULL){
        free(vector);
        return NULL;
    }
    return vector;
}
// récupère le nième élément
float get(struct vector_t * vector, int n){
    if (n >= vector->size){
        return NULL;
    }
    return *(vector->v + n);
}
// fixe la valeur du nième élément
void set(struct vector_t * vector, int n, float elem){
    if (n < vector->size){
        *(vector->v+n) = elem;
    }
}
// supprime un vecteur
void destroy(struct vector_t * vector){
    free(vector->v);
    free(vector);
}

// v = [1.2,54.0,12.8]
// v[n]