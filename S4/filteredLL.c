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
    if (!head){return NULL};
    size_t size = sizeof(struct node);
    struct node  * newHead = (struct node *) malloc(size);
    if (!newHead){return NULL;}
    memcpy(newHead, head, size);

    if (!(head->next)||!(head->next->next)){
        newHead->next = NULL;
        return newHead;
    }

    struct node* nextNode = newHead; // Pointer to the nextNode
    struct node* current = head->next->next; // Goes through the LL
    while(true){
        nextNode->next = (struct node*) malloc(size);
        if (!nextNode->next){return NULL;}
        memcpy(nextNode->next,current,size);
        nextNode = nextNode->next;
        if (!runner->next || !runner->next->next){
            break;
        }
    }
    nextNode = NULL;
    return newHead;
}