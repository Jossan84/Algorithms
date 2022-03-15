/*
TestBinaryTrees.c
15/03/2022
*/

#include <stdio.h>
#include <stdlib.h>

// Defining data for this Binary tree 
typedef char Data;

// Defining a node
typedef struct node{
    Data d;
    struct node  *left;
    struct node *right;
}Node;

// Defining a tree as a pointer to a node.
typedef Node* BTree;

// Standard in order traversal of a binary tree
void isOrder(BTree root){
    if(root != NULL){
        isOrder(root->left);
        printf("%c ", root->d);
        isOrder(root->right);
    }
}

// Creating a new node, not adding it to any tree yet, or even giving it data.
BTree newNode(void){
    return(malloc(sizeof(Node)));
}

// Creating and initializing a new node.
BTree initNode(Data d, BTree left, BTree right){
    BTree t;
    t = newNode();
    t->d = d;
    t->left = left;
    t->right = right;
    return t;
}

// This method creates a new tree recursively, i.e, for each node we will
// create its left and right subtrees and connect by that node.  
BTree createTree(Data a[], int i, int size){
    if (i>=size)
        return NULL;
    else
        return(initNode(a[i],
                    	createTree(a, 2*i+1, size),
						createTree(a, 2*i+2, size)));    
}

int main(void){
    char d[] = {'a','b','c','d','e'};
    BTree bt;
    bt = createTree(d, 0, 5);
    isOrder(bt);
    return 0;
}