#include <iostream>
#include "Linked_List.h"
int main() {
    Linked_List<float> l;
    l.Append(10.2);
    l.Append(12.3);
    l.Append(12.5);
    l.Append(13.7);
    l.insert(15.66,2);
    l.insert(16.7,3);
    l.insert(7.2,0);
    l.insert(1.9,7);
    l.erase(2);
    l.Display();
    cout<<"\nSUM : "<<l.sum();
    cout<<"\nMAX :"<<l.max();
    cout<<"\nMIN :"<<l.min();
    cout<<"\nElement 13.7 is found at index :"<<l.LinearSearch(13.7);
    return 0;
}
