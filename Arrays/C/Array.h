#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
Data:
    1.Array Space
    2.Size
    3.Length(no of elements)
Operations:
    1.Display()
    2.Add(x)/Append(x)
    3.Insert(index x)
    4.Delete(index)
    5.Search(x)
    6.Get(index)
    7.Set(index,x)
    8.max()/min()
    9.Reverse()
    10.shift()/rotate()
*/


typedef struct
{
    int *A;
    size_t size;
    int length;
}Array;


void constructArray(Array *arr);
void Display(Array arr);
void Append(Array *arr,int value);
void Insert(Array *arr,int index,int value);
int Delete(Array *arr,int index);
int LinearSearch(Array *arr,int value); // best O(1), worst O(n), average: = (n(n+1)/2)/n = (n+1)/2 O(n)
int BinarySearch(Array *arr,int value);
int getElement(Array arr,int index); //
void setElement(Array *arr,int index,int value);
int getMax(Array arr);
int getMin(Array arr);
int getSum(Array arr);
void Reverse(Array *arr);
int isSorted(Array arr);
void InsertSort(Array *arr,int x);
Array MergeSorted(Array *a, Array *b);
Array UnionSorted(Array *a, Array *b);
Array IntersectSorted(Array *a, Array *b);
Array DiffSorted(Array *a, Array *b);

#endif // ARRAY_H_INCLUDED
