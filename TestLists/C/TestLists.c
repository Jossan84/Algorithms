/*
TestLists.c
15/03/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defines the struct list
typedef struct list{ int data; struct list *next;}list;

// This method returns 1 or 0 based on whether or not argument list is empty
int isEmpty(const list *l){ return (l == NULL);}

// This method initializes a head of a list and returns it
list *createList(int d){
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

// This method takes an integer and a list, creates a new head with argument data and makes it 
// argument list's head. Returns new head
list *add2Front(int d, list *h){
    list *head = createList(d);
    head -> next = h;
    return head;
}

// This method takes an array, initializes a new list with arrays elements as elements and
// returns list head
list *array2List(int d[], int size){
    list *head = createList(d[0]);
    int i;
    for(i = 1; i< size; i++){
        head = add2Front(d[i], head);
    }
    return head;
}

// This method prints the title of parameter list, followed by as line of this list's elements
void printList(list *h, char *title){
    printf("%s\n", title);
    while(h != NULL){
        printf("%d :", h->data);
        h = h->next;
    }
}

// This method swaps the data of two given pointers to different nodes in a linked list
void swapNodes(list *p1, list *p2){
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
    return;
}

// This method uses bubble sort in order to sort a given list
void sortList(list *h, int size){
    int i, j;
    list *p1, *p2;

    /*  For each iteration we will consider two adjacent pointers
        always starting at the beggining of the list. 
        i will represent the number of times we will move the pointers one step ahead
        decreasing as we bubble more and more element to the end of the list
    */
    for(i = size-2; i >= 0; i--){
        p1 = h;
        p2 = p1->next;
        for(j = 0; j <= i; j++){
            if(p1->data > p2->data)
                swapNodes(p1, p2);
            p1 = p2;
            p2 = p2->next;
        }
    }
}


int main(void){
    list l;
    list *head = NULL;
    int data[] = {2,3,5,7,8,9};
    head = array2List(data, 6);
    printList(head, "My list: ");
    return 0;
}