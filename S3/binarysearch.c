/*
Returns 1 if there is a node containing @value in @tree and 0 otherwise.
*/

#include <stdio.h>
#include <stdlib.h>


/*
* Node has a value, @value, and two children, @left and @right.
* All the children of @left and itself have a smaller value than the node and all the children of @right and itself have a larger value than node
*/
typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;

typedef struct bt{
    struct node* root;
} bt_t;

int contains_aux(node_t* n, int value){
    if(!n){
        return 0;
    }
    if(n->value == value){
        return 1;
    }
    if(n->value > value){
        return contains_aux(n->left,value);
    }
    return contains_aux(n->right,value);
}


int contains(bt_t* tree, int value){
    if(!tree) return 0;
    return contains_aux(tree->root,value);
}

// TESTS

int main(void){
    node_t node1 = {13,NULL,NULL};
    node_t * node1_ptr = &node1;
    node_t node2 = {17,NULL,NULL};
    node_t * node2_ptr = &node2;
    node_t node3 = {16,node1_ptr,node2_ptr};
    node_t * node3_ptr = &node3;
    node_t node4 = {7,NULL,NULL};
    node_t * node4_ptr = &node4;
    node_t node5 = {11,node4_ptr,node3_ptr};
    node_t * node5_ptr = &node5;
    node_t node6 = {23,NULL,NULL};
    node_t * node6_ptr = &node6;
    node_t node7 = {35,node6_ptr,NULL};
    node_t * node7_ptr = &node7;
    node_t node8 = {19,node5_ptr,node7_ptr};
    node_t * node8_ptr;
    node8_ptr = &node8;
    bt_t tree = {node8_ptr};
    bt_t * tree_ptr = &tree;
    printf("%d\n", contains(tree_ptr,13));
}