/*
Implements the stack data-structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char *name;
};


/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result){
    if (!head){return 1;}
    strncpy(result,(*head)->name,strlen((*head)->name)+1);
    struct node *old = *head;
    *head = (*head)->next;
    free(old->name);
    free(old);
return 0;
}


/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value){
    struct node node;
    node.name = (char*) malloc(sizeof(char)*(strlen(value)+1));
    if (node.name == NULL){return 1;}
    strcpy(node.name,value);
    if (head == NULL){return 1;}
    node.next = *head;
    struct node * newNode = (struct node*) malloc(sizeof(node));
    if (newNode != NULL){
        *newNode = node;
        *head = newNode;
        return 0;
    }
    return 1;
}