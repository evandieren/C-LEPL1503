/*
Implements the queue data-structure.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node{
  struct node* next;
  int value;
} node_t;

typedef struct queue{
  struct node* tail;
  int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val     : the value to enqueue
* @q     : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val){
    node_t * NewNode = (node_t*) malloc(sizeof(node_t));
    if (NewNode == NULL) {return -1;}
    NewNode->value = val;

    if (q->size == 0){
        NewNode->next = NewNode;
        q->tail = NewNode;
        q->size ++;
        return 0;
    }

    NewNode->next = (q->tail)->next;
    (q->tail)->next = NewNode;
    q->size++;
    return 0;
}

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q         : the queue
* @return     : the value at the tail
*
* pre         : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q){
    int ret = (q->tail)->value;
    if (q->size == 1){
        free(q->tail);
        q->tail = NULL;
        q->size --;
        return ret;
    }

    node_t * runner = q->tail;

    for (int i = 1; i < q->size; i++){
        runner = runner->next;
    }

    runner->next = (q->tail)->next;

    free(q->tail);
    q->tail = runner;
    q->size --;
    return ret;
}