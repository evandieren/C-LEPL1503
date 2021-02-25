/*
Create a Linked List ordered with a specific comparator.
*/

#include <stdio.h>
#include <stdlib.h>


/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) {
    return a - b;
}

typedef struct node{
    char val;
    struct node *next;
} node_t;


/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char)) {
    // EMPTY LIST

    node_t * runner = *head;
    node_t * previous = *head;

    // 1 ELEMENT
    int gol = (*cmp)(val,runner->val);
    if (gol == 0){return 0;} //car les if imbrique c'est sale
    if (gol < 0){
        node_t * newNode = (node_t *) malloc(sizeof(node_t));
        if (newNode == NULL){return -1;}
        newNode->val = val;
        newNode->next = runner;
        *head = newNode;
        return 0;
    }

    // + de 1 élément
    // Boucle dans la LL jusqu'à trouver un élément tel que val < runner->val, ou alors atteint la fin de la liste
    runner = runner->next;
    while((runner != NULL) && ((*cmp)(val,runner->val) >= 0)){
        if((*cmp)(val,runner->val) == 0){return 0;}
        previous = runner;
        runner = runner->next;
    }

    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    if(newNode == NULL) {return -1;}
    newNode->val = val;
    newNode->next = runner;
    previous->next = newNode;
    return 0;
}

