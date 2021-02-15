/*
Swaps the numerator and denominator of two fractions a and b.
*/

struct fract_t {
        int num;
        int denum;
};

void swap(struct fract_t *a, struct fract_t *b){
    int numtemp  = a->num;
    int denumtemp  = a->denum;
    a->num = b->num;
    a->denum = b->denum;
    b->num = numtemp;
    b->denum = denumtemp;
}