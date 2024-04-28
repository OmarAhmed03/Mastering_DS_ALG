
#include "Array.h"



int main()
{

    Array<float> *arr1;
    arr1 = new Array<float> (1);
    arr1->Append(0.1);
    arr1->Append(0.1);
    arr1->Append(0.1);
    arr1->Append(0.1);
    arr1->Display();
    return 0;
}
