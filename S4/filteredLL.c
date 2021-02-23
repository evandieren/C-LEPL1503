/*
Filters a linked List by only keeping the elements with an even index (0,2,4,6,...). It returns a new LL and keep the original one unchanged.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    int hash;
    int id;
    char name[20];
    char buffer[100];
    unsigned int timestamp;
    char acl;
    short flow;
    char *parent;
    void *fifo;
};


/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head) {
    if (head==NULL)
    return NULL;

    struct node *nHead = malloc(sizeof(struct node));

    if (!nHead){
        return NULL;
    }
    memcpy(nHead,head,sizeof(struct node));
    if (head -> next != NULL){
        nHead->next = pair_filter(head->next->next);
    }
    return nHead;
}