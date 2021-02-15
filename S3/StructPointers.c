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
    char str[strlen(ptrProd->name)];
	char * name;
	name = (char*) malloc(sizeof(struct product));
	if (name != NULL){
		name = ptrProd->name;
	}
	return name;
}
	

/*
 * @name in prod != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getName(product_t prod){
	return prod.name;
}

/*
 * @ptrProd != NULL
 * @name in ptrProd != NULL
 * @name in prod != NULL
 * @return: 1 if the two products are the same, i.e., they have the same price and the same name
 */
int prodEquals(product_t *ptrProd, product_t prod){
	if ((getPtrPrice(ptrProd) == getPrice(prod)) && (getPtrName(ptrProd) == getName(prod))){
		return 1;
	}
	return 0;
}
