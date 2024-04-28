#ifndef ARRAY_H
#define ARRAY_


#include <iostream>


using namespace std;

template<typename T>
class Array
{
    public:
        Array(int size)
        {
            this->size = size;
            A = new T[size];
            length = 0;
            //ctor
        }
        Array()
        {
            this->size = 10;
            A = new T[size];
            length = 0;
            //ctor
        }
        ~Array()
        {
            //dtor
            delete []A;
        }

        void Display();
        void Append(T value);
        void Insert(int index,T value);
        T Delete(int index);
        int LinearSearch(T value); // best O(1), worst O(n), average: = (n(n+1)/2)/n = (n+1)/2 O(n)
        int BinarySearch(T value);
        T getElement(int index); //
        void setElement(int index,T value);
        T getMax();
        T getMin();
        T getSum();
        void Reverse();
        int isSorted();
        void InsertSort(T value);
        Array<T> MergeSorted(Array<T> *b);
        Array<T> UnionSorted(Array<T> *b);
        Array<T> IntersectSorted(Array<T> *b);
        Array<T> DiffSorted(Array<T> *b);

    private:
        T *A;
        int size;
        int length;
        void copy_carray(T* source, int sourceSize, T* destination, int destinationSize);
        void increase_size();
};
template<typename T>
void Array<T>::copy_carray(T* source, int sourceSize, T* destination, int destinationSize) {
    size_t elementsToCopy = (sourceSize < destinationSize) ? sourceSize : destinationSize;

    memcpy(destination, source, elementsToCopy * sizeof(int));
}

template<typename T>
void Array<T>::increase_size()
{
    T *B;
    int new_size = 2*size;
    B = new T[new_size];
    copy_carray(A,size,B,2*size);
    A = B;
    size = new_size;
    //delete []B;
}


template<typename T>
void Array<T>::Display()
{
    int i;
    //printf("elements are: ");
    for (i = 0;i<length;i++){
        cout<<A[i]<<endl;
    }
}

template<typename T>
void Array<T>::Append(T value)
{
    if(length >= size){
        increase_size();}
    A[length] = value;
    length++;
}
template<typename T>
void Array<T>::Insert(int index,T value)
{
    if(index - size <= size){
       if(index >= size){
        increase_size();}
    else if (index < size){
        int i;
        for (i = length;i > index;i--){;
            A[i] = A[i-1];
    }}
    A[index] = value;
    length++;}
    else
        return;
}
template<typename T>
T Array<T>::Delete(int index)
{
    int i;
    if (index >= 0 && index < length){
        T x = A[index];
        for(i = index; i < length -1 ;i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}
template<typename T>
int Array<T>::LinearSearch(T value)
{
    int found = -1;
    int i;
    for (i = 0;i<length;i++){
        if(value == A[i]){
            found = i;
            break;
        }
    }
    return found;
}
template<typename T>
int Array<T>::BinarySearch(T value)
{
    int l = 0;
    int h = length;
    int middle;
    while (l<=h){
        middle = (l+h)/2;
        if (value == A[middle]){
            return middle;
        }
        else if(value < A[middle]){
            h = middle - 1;
            //BinarySearch(arr,value,l,h);
        }
        else if(value > A[middle]){
            l = middle + 1;
            //BinarySearch(arr,value,l,h);
        }
    }
    return -1;
}
template<typename T>
T Array<T>::getElement(int index)
{
    if (index >=0 && index < length)
    return A[index];
}
template<typename T>
void Array<T>::setElement(int index,T value)
{
    if (index >=0 && index < length)
    A[index] = value;
}

template<typename T>
T Array<T>::getMax()
{
    T max = A[0];
    for(int i = 1; i < length; i++){
        if (A[i] > max)
            max = A[i];
    }
    return max;

}

template<typename T>
T Array<T>::getMin()
{
    T min = A[0];
    for(int i = 1; i < length; i++){
        if (A[i] < min)
            min = A[i];
    }
    return min;

}
template<typename T>
T Array<T>::getSum()
{
    T sum = A[0];
    for(int i = 1; i < length; i++){
        sum += A[i];
    }
    return sum;
}

template<typename T>
void Array<T>::Reverse()
{
    int i,j;
    T temp;
    for(j = length-1,i = 0; i<j; i++,j--){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

template<typename T>
int Array<T>::isSorted()
{
    int sorted = 1;
    for (int i = 0;i<length;i++){
        if (A[i] > A[i+1]){
            sorted = 0;
        }
    }
    return sorted;
}
template<typename T>
void Array<T>::InsertSort(T x)
{
    int i;
    i = length - 1;
    if (length == size)
        return;
    while(A[i] > x && i >= 0){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}
template<typename T>
Array<T> Array<T>::MergeSorted(Array<T> *b)
{
    int m = length;
    int n = b->length;


    Array<T> c(m+n);
    int i=0;int j = 0;int k = 0;
    while(i < m && j < n){
        if(A[i] < b->A[j]){
            c.A[k++] = A[i++];
        }
        else{
            c.A[k++] = b->A[j++];
        }

    }

    for(;i<m;i++){
        c.A[k++] = A[i];
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
    }
    return c;
}
template<typename T>
Array<T> Array<T>::UnionSorted(Array *b)
{
    int m = length;
    int n = b->length;


    Array<T> c(m+n);
    int i=0;int j = 0;int k = 0;

    while(i < m && j < n){
        if(A[i] < b->A[j]){
            c.A[k++] = A[i++];
            c.length++;
        }
        else if(A[i] > b->A[j]){
            c.A[k++] = b->A[j++];
            c.length++;
        }
        else{
            c.A[k++] = b->A[j];
            c.length++;
            i++;
            j++;
        }

    }

    for(;i<m;i++){
        c.A[k++] = A[i];
        c.length++;
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
        c.length++;
    }
    return c;
}
template<typename T>
Array<T> Array<T>::IntersectSorted(Array *b)
{
    int m = length;
    int n = b->length;


    Array<T> c(m+n);
    int i=0;int j = 0;int k = 0;
    while(i < m && j < n){
        if(A[i] == b->A[j]){
            c.A[k++] = A[i++];
            c.length++;
            j++;}
        else{
            i++;
            j++;
        }

    }

    for(;i<m;i++){
        c.A[k++] = A[i];
        c.length++;
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
        c.length++;
    }
    return c;
}
template<typename T>
Array<T> Array<T>::DiffSorted(Array *b)
{
    int m = length;
    int n = b->length;


    Array<T> c(m+n);
    int i=0;int j = 0;int k = 0;
    while(i < m && j < n){
        if(A[i] < b->A[j]){
            c.A[k++] = A[i++];
            c.length++;
        }
        else if(A[i] > b->A[j]){
            c.A[k++] = b->A[j++];
            c.length++;
        }
        else{
            i++;
            j++;
        }

    }

    for(;i<m;i++){
        c.A[k++] = A[i];
        c.length++;
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
        c.length++;
    }
    return c;
}


#endif // ARRAY_H
