#include "linked_lists.h"

void createLL(Linked** ll)
{
    *ll = (Linked*)malloc(sizeof(Linked));
    (*ll)->head = NULL;
    (*ll)->tail = NULL;
}

void AppendLL(Linked* ll,int x)
{
    Node* e = (Node* )malloc(sizeof(Node));
    e->data =x;
    e->next = NULL;
    if(isEmpty(ll)){
        ll->head = e;
        ll->tail = e;
    }
    else{
        ll->tail->next = e;
        ll->tail = e;
    }
}

void DisplayLL(Linked* ll)
{
    Node* e = ll->head;
    while(e != NULL){
        printf("%d \n", e->data);
        e = e->next;
    }
}

int sizeLL(Linked* ll)
{
    int count = 0;
    Node* e = ll->head;
    while(e != NULL){
        count++;
        e = e->next;
    }
    return count;
}

int isEmpty(Linked* ll)
{
    if(ll->head == NULL){
        return 1;
    }
    return 0;
}

int sumLL(Linked* ll)
{
    int sum = 0;
    Node* e = ll->head;
    while(e != NULL){
        sum += e->data;
        e = e->next;
    }
    return sum;
}

int maxLL(Linked* ll)
{

    Node* e = ll->head;
    int max = MIN_INT;
    while(e != NULL){
        if(e->data > max){
            max = e->data;
        }
        e = e->next;
    }
    return max;
}

int minLL(Linked* ll)
{
    Node* e = ll->head;
    int min = MAX_INT;
    while(e != NULL){
        if(e->data < min){
            min = e->data;
        }
        e = e->next;
    }
    return min;
}

int LinearSearch(Linked* ll,int x)
{
    Node* e = ll->head;
    int index = 0;
    while(e != NULL){
        if(e->data == x){
            return index;
        }
        e = e->next;
        index++;
    }
    return -1;

}

void insertLL(Linked* ll, int x, int index) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL; // Ensure the new node's next pointer is initially NULL

    if (index == 0) { // Insert at the beginning
        if (ll->head == NULL) { // If list is empty
            ll->head = t;
            ll->tail = t;
        } else {
            t->next = ll->head;
            ll->head = t;
        }
    } else { // Insert at index > 0
        Node* h = ll->head;
        int i;
        for (i = 0; i < index - 1 && h != NULL; i++) { // Traverse to the node before the insertion point
            h = h->next;
        }
        if (i == index - 1 && h != NULL) { // If the index is within the bounds of the list
            t->next = h->next;
            h->next = t;
            if (t->next == NULL) { // If the new node becomes the new tail
                ll->tail = t;
            }
        } else { // If the index is beyond the end of the list
            printf("Index out of bounds.\n");
            free(t); // Free the allocated memory for the new node
        }
    }
}

void eraseLL(Linked* ll, int index)
{
    Node *h = ll->head;
    if (index == 0){

        ll->head = h->next;
        free(h);
    }
    else{
        for (int i = 0;i < index -1 ;i++){
            h = h->next;
        }
        Node* t = h->next;
        h->next = t->next;
        free(t);


    }
}
int value_n_from_end(Linked* ll,int x)
{
    Node* m = ll->head; Node* n = ll->head;
    int i = 1;
    if (isEmpty(ll) || sizeLL(ll) < n){
        return MIN_INT;
    }
    while(m != NULL){
        m = m->next;
        if(i > x){
            n= n->next;
        }
        i++;
    }
    return n->data;

}

void reverseLL(Linked* LL)
{

}

