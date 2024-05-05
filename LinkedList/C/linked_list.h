#ifndef LINKED_LISTS_H_INCLUDED
#define LINKED_LISTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MIN_INT -32768
#define MAX_INT 32768


typedef struct Node
{
        int data;
        struct Node* next;
}Node;

typedef struct Linked
{
        Node* head;
        Node* tail;
}Linked;



void createLL(Linked**);
int isEmpty(Linked* ll);
void AppendLL(Linked* ll,int x);
void DisplayLL(Linked* ll);
int sizeLL(Linked* ll);
int sumLL(Linked* ll);
int maxLL(Linked* ll);
int minLL(Linked* ll);
int LinearSearch(Linked* ll,int x);
void insertLL(Linked* ll,int x,int index);
void eraseLL(Linked* ll,int index);
int value_n_from_end(Linked* ll,int x);
void reverseLL(Linked* LL);


#endif // LINKED_LISTS_H_INCLUDED
