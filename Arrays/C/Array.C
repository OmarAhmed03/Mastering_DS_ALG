#include "Array.h"


void constructArray(Array *arr)
{
    int n,i;
    printf("Enter the size of the array\n");
    scanf("%d",&arr->size);
    arr->A = (int* )malloc(arr->size*sizeof(int));
    arr->length = 0;

    printf("Eter the number of the elements\n");
    scanf("%d",&n);

    printf("Eter the elements\n");
    for (int i = 0;i<n;i++){
        scanf("%d",&arr->A[i]);
    }
    arr->length += n;
}

void Display(Array arr)
{
    int i;
    printf("elements are: ");
    for (i = 0;i<arr.length;i++){
        printf("%d  ",arr.A[i]);
    }
    printf("\n");
}

void Append(Array *arr,int value)
{
    if(arr->length < arr->size){
    arr->A[arr->length] = value;
    arr->length++;}
}
void Insert(Array *arr,int index,int value)
{
    if (index < arr->size){
    int i;
    for (i = arr->length;i > index;i--){;
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = value;
    arr->length++;}
}
int Delete(Array *arr,int index)
{
    int i;
    if (index >= 0 && index < arr->length){
        int x = arr->A[index];
        for(i = index; i < arr->length -1 ;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
int LinearSearch(Array *arr,int value)
{
    int found = -1;
    int i;
    for (i = 0;i<arr->length;i++){
        if(value == arr->A[i]){
            found = i;
            break;
        }
    }
    return found;
}
int BinarySearch(Array *arr,int value)
{
    int l = 0;
    int h = arr->length;
    int middle;
    while (l<=h){
        middle = (l+h)/2;
        if (value == arr->A[middle]){
            return middle;
        }
        else if(value < arr->A[middle]){
            h = middle - 1;
            //BinarySearch(arr,value,l,h);
        }
        else if(value > arr->A[middle]){
            l = middle + 1;
            //BinarySearch(arr,value,l,h);
        }
    }
    return -1;
}
int getElement(Array arr,int index)
{
    if (index >=0 && index < arr.length)
    return arr.A[index];
}
void setElement(Array *arr,int index,int value)
{
    if (index >=0 && index < arr->length)
    arr->A[index] = value;
}

int getMax(Array arr)
{
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;

}

int getMin(Array arr)
{
    int min = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;

}
int getSum(Array arr)
{
    int sum = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        sum += arr.A[i];
    }
    return sum;
}

void Reverse(Array *arr)
{
    int i,j,temp;
    for(j = arr->length-1,i = 0; i<j; i++,j--){
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int isSorted(Array arr)
{
    int sorted = 1;
    for (int i = 0;i<arr.length;i++){
        if (arr.A[i] > arr.A[i+1]){
            sorted = 0;
        }
    }
    return sorted;
}
void InsertSort(Array *arr,int x)
{
    int i;
    i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while(arr->A[i] > x && i >= 0){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}
Array MergeSorted(Array *a,Array *b)
{
    int m = a->length;
    int n = b->length;

    int *z = (int *)malloc((m+n)*sizeof(int));
    Array c = {z,m+n+1,m+n};

    int i=0;int j = 0;int k = 0;
    while(i < m && j < n){
        if(a->A[i] < b->A[j]){
            c.A[k++] = a->A[i++];
        }
        else{
            c.A[k++] = b->A[j++];
        }

    }

    for(;i<m;i++){
        c.A[k++] = a->A[i];
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
    }
    return c;
}
Array UnionSorted(Array *a, Array *b)
{
    int m = a->length;
    int n = b->length;

    int *z = (int *)malloc((m+n)*sizeof(int));
    Array c = {z,m+n+1,0};

    int i=0;int j = 0;int k = 0;
    while(i < m && j < n){
        if(a->A[i] < b->A[j]){
            c.A[k++] = a->A[i++];
            c.length++;
        }
        else if(a->A[i] > b->A[j]){
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
        c.A[k++] = a->A[i];
        c.length++;
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
        c.length++;
    }
    return c;
}
Array IntersectSorted(Array *a, Array *b)
{
    int m = a->length;
    int n = b->length;

    int *z = (int *)malloc((m+n)*sizeof(int));
    Array c = {z,m+n+1,0};

    int i=0;int j = 0;int k = 0;
    while(i < m && j < n){
        if(a->A[i] == b->A[j]){
            c.A[k++] = a->A[i++];
            c.length++;
            j++;}
        else{
            i++;
            j++;
        }

    }

    for(;i<m;i++){
        c.A[k++] = a->A[i];
        c.length++;
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
        c.length++;
    }
    return c;
}
Array DiffSorted(Array *a, Array *b)
{
    int m = a->length;
    int n = b->length;

    int *z = (int *)malloc((m+n)*sizeof(int));
    Array c = {z,m+n+1,0};

    int i=0;int j = 0;int k = 0;
    while(i < m && j < n){
        if(a->A[i] < b->A[j]){
            c.A[k++] = a->A[i++];
            c.length++;
        }
        else if(a->A[i] > b->A[j]){
            c.A[k++] = b->A[j++];
            c.length++;
        }
        else{
            i++;
            j++;
        }

    }

    for(;i<m;i++){
        c.A[k++] = a->A[i];
        c.length++;
    }
    for(;j<n;j++){
        c.A[k++] = b->A[j];
        c.length++;
    }
    return c;
}
