//
// Created by asus on 5/5/2024.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../../../../../Program Files/CLion 2024.1.1/bin/mingw/x86_64-w64-mingw32/include/stddef.h"
#include <iostream>

using namespace std;
template <typename T>
class Linked_List {
public:
    Linked_List();
    ~Linked_List();
    bool isEmpty();
    void Append(T x);
    void Display();
    int size();
    T sum();
    T max();
    T min();
    int LinearSearch(T x);
    void insert(T x,int index);
    void erase(int index);
    T value_n_from_end(T x);
    void reverse();


private:
    typedef struct Node
    {
        T data;
        struct Node* next;
    }Node;

    Node* head;
    size_t listsize;
};


template <typename T>
Linked_List<T>::Linked_List() {
    head = nullptr;
    listsize = 0;
}

template <typename T>
Linked_List<T>::~Linked_List() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T> bool
Linked_List<T>::isEmpty() {
     if (head == nullptr) {
         return true;
     }
    return false;
}

template <typename T> void
Linked_List<T>::Append(T x) {
    Node* t = new Node;
    Node* h = head;
    t->data = x;
    t->next = nullptr;
    if (isEmpty()) {
        head = t;
        head->next = nullptr;
    }
    else {
        while(h->next != nullptr) {
            h = h->next;
        }
        h->next = t;
    }
    ++listsize;
}

template <typename T> void
Linked_List<T>::Display() {
    Node* h = head;
    while(h != nullptr) {
        cout<<h->data<<" ";
        h = h->next;
    }
}

template <typename T> int
Linked_List<T>::size() {
    return listsize;
}

template <typename T> T
Linked_List<T>::sum() {
    Node* h = head;
    T sum = 0;
    while(h != nullptr) {
        sum += h->data;
        h = h->next;
    }
    return sum;
}

template <typename T> T
Linked_List<T>::max() {
    Node* h = head;
    T max = h->data;
    while(h != nullptr) {
        max = (h->data > max) ? h->data : max;
        h = h->next;
    }
    return max;
}

template <typename T> T
Linked_List<T>::min() {
    Node* h = head;
    T min = h->data;
    while(h != nullptr) {
        min = (h->data < min) ? h->data : min;
        h = h->next;
    }
    return min;
}

template <typename T> int
Linked_List<T>::LinearSearch(T x) {
    Node* h = head;
    int found = -1;
    int index = 0;
    while(h != nullptr) {
        if (h->data == x) {
            found = index;
            break;
        }
        h = h->next;
        index++;
    }
    return found;
}

template <typename T> void
Linked_List<T>::insert(T x, int index) {
    Node* t = new Node;
    Node* h = head;
    t->data = x;
    t->next = nullptr;
    if (index >= listsize) {
        return;
    }
    if (index == 0) {
        t->next = head;
        head = t;
    }
    else {
        for(int i = 0;i<index;i++) {
            h = h->next;
        }
        t->next = h->next;
        h->next = t;
    }
    ++listsize;
}

template <typename T> void
Linked_List<T>::erase(int index) {
    if (index >= listsize || isEmpty()) return;

    Node* toDelete;
    if (index == 0) {
        toDelete = head;
        head = head->next;
    } else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        toDelete = temp->next;
        temp->next = toDelete->next;
    }
    delete toDelete;
    --listsize;

}

template <typename T> T
Linked_List<T>::value_n_from_end(T x) {

}

template <typename T> void
Linked_List<T>::reverse() {

}




#endif //LINKED_LIST_H
