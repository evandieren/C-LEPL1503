#include <stdio.h>
#include <stdlib.h>

typedef struct product {
    char *name;
    double price;
} product_t;

/*
 * @ptrProd != NULL
 * @return: the price of the product ptrProd
 */
double getPtrPrice(product_t *ptrProd){
	return ptrProd->price;
}

/*
 * @return: the price of the product prod
 */
double getPrice(product_t prod){
	return prod.price;
}

/*
 * ptrProd != NULL
 * @name in ptrProd != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getPtrName(product_t *ptrProd){
    char *dest = (char *) malloc(strlen(ptrProd->name) + 1); // +1 pour le '\0'
    if (dest != NULL){
        strcpy(dest,ptrProd->name);
    }
    return dest;
}
	

/*
 * @name in prod != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getName(product_t prod){
	char * dest = (char *) malloc(strlen(prod.name) + 1);
	if (dest != NULL){
	    strcpy(dest,prod.name);
	}
	return dest;
}

/*
 * @ptrProd != NULL
 * @name in ptrProd != NULL
 * @name in prod != NULL
 * @return: 1 if the two products are the same, i.e., they have the same price and the same name
 */
int prodEquals(product_t *ptrProd, product_t prod){
	int same_price = getPtrPrice(ptrProd) == getPrice(prod);
    int same_name = !strcmp(ptrProd->name,prod.name);
    return same_price && same_name;
}
