
#include "Array.h"



int main()
{

    Array arr1;
    int ch;
    int x,index;

    printf("Enter Size of Array");
    scanf("%d",&arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("enter you choice ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("Enter an element and index");
            scanf("%d%d",&x,&index);
            Insert(&arr1,index,x);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d",&index);
            x=Delete(&arr1,index);
            printf("Deleted Element is %d\n",x);
            break;
        case 3:
            printf("Enter element to search ");
            scanf("%d",&x);
            index=LinearSearch(&arr1,x);
            printf("Element index %d",index);
            break;
        case 4:
            printf("Sum is %d\n",getSum(arr1));
            break;
        case 5:
            Display(arr1);

        }
    }
    while(ch<6);

    return 0;
}


















/*
int main()
{
    int *x = (int *)malloc(10*sizeof(int));
    int *y = (int *)malloc(10*sizeof(int));
    Array a = {x,10,0};
    Array b = {y,10,0};
    int i,j;
    for (i = 1;i<=5;i++){
        x[i-1] = 4*i-3;
        //y[j] = 2*i +1;
        a.length++;
    }
    for (j = 1;j<=7;j++){
        y[j-1] = 2*j +1;
        b.length++;
    }
    Array c = UnionSorted(&a,&b);
    Array d = MergeSorted(&a,&b);
    Array e = IntersectSorted(&a,&b);
    Array f = DiffSorted(&a,&b);
    //constructArray(&arr);
    //Display(arr);
    //Append(&arr,20);
    //Insert(&arr,3,15);
    //Delete(&arr,1);
    //printf("\n elements is at index %d \n",BinarySearch(&arr,1));
    //setElement(&arr,1,12);
    //printf("\n max element: %d \n",getMax(arr));
    //printf("\n min element: %d \n",getMin(arr));
    //printf("\n sum of elements: %d \n",getSum(arr));
    //printf("\n elements is at index 3: %d \n",getElement(arr,3));
    printf("Array 1: ");
    Display(a);
    printf("Array 2: ");
    Display(b);
    printf("Array 1 U Array 2: ");
    Display(c);
    printf("Array 1 merged Array 2: ");
    Display(d);
    printf("Array 1 intersected Array 2: ");
    Display(e);
    printf("Array 1 - Array 2: ");
    Display(f);
    //Display(arr);
    //printf("%d",isSorted(arr));

    return 0;
}

*/

