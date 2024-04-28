
#include "Array.h"



int main()
{
    Array<float> *arr1;
    int ch,sz;
    int index;
    float x;

    printf("Enter Size of Array");
    scanf("%d",&sz);
    arr1 = new Array<float> (sz);
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
            cout<<"Enter an element and index"<<endl;
            cin>>x>>index;
            arr1->Insert(index,x);
            break;
        case 2:
            cout<<"Enter index "<<endl;
            cin>>index;
            x=arr1->Delete(index);
            cout<<"Deleted Element is\n"<<x;
            break;
        case 3:
            cout<<"Enter element to search "<<endl;;
            cin>>x;
            index=arr1->LinearSearch(x);
            cout<<"Element index"<<index<<endl;
            break;
        case 4:
            cout<<"Sum is %d\n"<<arr1->getSum()<<endl;
            break;
        case 5:
            arr1->Display();

        }
    }
    while(ch<6);
    
    return 0;
}
