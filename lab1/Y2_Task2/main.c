#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


void printArray(int B[], int len){
    printf("printArray\n");
    for(int i=0; i< len; i++)
    {
        printf("t[%d]=%d, ", i, B[i]);
    }
    printf("\n");
}


void printArrayByPtr(int* ptr, int len){
    printf("printArrayByPtr\n");
    for(int i=0; i< len; i++)
    {
        printf("t[%d]=%d, ", i, *(ptr+i) );
    }
    printf("\n");
}

void incFirstAndLast(int* ptr, int len){
    printf("incFirstAndLast\n");
    if(len > 0){
        *(ptr) = *(ptr) + 100; //*(ptr+0) += 100;
        if(len > 1)
        {
            *(ptr+len-1) = *(ptr+len-1) + 100;
        }
    }
}

int* createArrayByMA(int len){
    printf("createArrayByMA\n");
    int* ptrNewArray = (int*) malloc(len * sizeof(int));
    return ptrNewArray;
}

int* createArrayByCA(int len){
    printf("createArrayByCA\n");
    int* ptrNewArray = (int*) calloc(len, sizeof(int));
    return ptrNewArray;
}

void fillArray(int* ptr, int len, int newValue){
    printf("fillArray\n");
    for(int i=0; i< len; i++)
    {
        *(ptr+i) = newValue;
    }
}
/** \brief
 *
 * \param  scopeMin is from closed
 * \param  scopeMax is thru closed
 * \return
 *
 */
void t5fillArrayByRandomWithScopeMaxAnMinValueAndSwampBigerScope(int* ptr, int len, int scopeMin, int scopeMax){
    printf("fillArrayByRandom\n");
    srand(time(NULL));

    if(scopeMin > scopeMax)
    {
        int temp = scopeMax;
        scopeMax = scopeMin;
        scopeMin = temp;

    }
    for(int i=0; i< len; i++)
    {
        *(ptr+i) = (rand() % (scopeMax - scopeMin + 1) ) + scopeMin;
    }
}

int main()
{
    printf("Task2!\n");
    //enum enums_size {s = 10};
    int A[10];
    int B[] = {1,2,3,4,5,6,7,8,9,10};
    int C[5] = { 0 };
    int* ptrB = &B[0]; //B
    int len = sizeof(B)/sizeof(int); // sizeof(B[0]);
    //printf("len =%d\n\n", len);

    printArray(B, len);
    //printArray(ptrB, len);
    //printArrayByPtr(B, len);
    printArrayByPtr(ptrB, len);

    incFirstAndLast(ptrB, len);
    printArrayByPtr(ptrB, len);

    int len2 = 15;
    int* ptr2 = createArrayByMA(len2);
    printArrayByPtr(ptr2, len2);

    int len3 = 6;
    int* ptr3 = createArrayByCA(len3);
    printArrayByPtr(ptr3, len3);

    free(ptr3);

    fillArray(ptr2, len2, 2);
    printArrayByPtr(ptr2, len2);
    //free(ptr2);

    t5fillArrayByRandomWithScopeMaxAnMinValueAndSwampBigerScope(ptr2, len2, 5, 1);
    printArrayByPtr(ptr2,len2);

    free(ptr2);


    return 0;
}
