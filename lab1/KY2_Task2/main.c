#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


void printArray(int C[], int len){
    printf("printArray\n");
    for(int i = 0; i<len; i++){
        printf("C[%d]=%d, ", i, C[i]);
    }
    printf("\n");
}

void printArrayByPtr(int* ptrC, int len){
    printf("printArrayByPtr\n");
    for(int i = 0; i<len; i++){
        printf("C[%d]=%d, ", i, *(ptrC+i) ) ;
    }
    printf("\n");
}

void incFirstAndLastElement(int* ptrC, int len, int incValue)
{
    printf("incFirstAndLastElement\n");
    if(len >0)
    {
        *(ptrC) += incValue;
        *(ptrC + len -1) += incValue;
    }
    for(int i = 0; i<len; i++){
        if(i == 0)
        {
            *(ptrC+i) += incValue;

        }
        else if (i == len -1)
        {
            *(ptrC+i) += incValue;
        }
    }
}

int* createArrayByMA(int len)
{
    printf("createArrayByMA\n");
    int* ptr =  (int*)malloc(len * sizeof(int));
    return ptr;
}

int* createArrayByCA(int len)
{
    printf("createArrayByCA\n");
    int* ptr =  (int*)calloc(len, sizeof(int));
    return ptr;
}

void fillArrayByValue(int* ptrA, int len, int value){
    printf("fillArrayByValue\n");
    for(int i = 0; i<len; i++){
        *(ptrA+i) = value;
    }
}

void fillArrayByRandom(int* ptrA, int len, int scopeMin, int scopeMax){
    srand(time(NULL));
    printf("fillArrayByRandom\n");
    for(int i = 0; i<len; i++){
        *(ptrA+i) = (rand() % scopeMax) +scopeMin;
    }
}




int main()
{
    printf("TASK2!\n");


    int A[SIZE] = { 0 };
    int B[] = { 0,0,0,0,0 };
    int C[] = { 0,1,2,33,4,5,6,7,8,9 };
    int D[SIZE];


    int len = sizeof(C)/sizeof(int);//sizeof(C[0]);
    int* ptrC = &C[0]; // C;


    printArray(C, len);
    printArrayByPtr(ptrC, len);
    printArrayByPtr(C, len);
    printArrayByPtr(&C[0], len);


    incFirstAndLastElement(ptrC, len, 100);
    printArrayByPtr(ptrC, len);

    int len1 = 5;
    int* ptr1 = createArrayByMA(len1);
    printArrayByPtr(ptr1, len1);

    int len2 = 5;
    int* ptr2 = createArrayByCA(len2);
    printArrayByPtr(ptr2, len2);

    free(ptr2);
    //free(ptr1);

    printArrayByPtr(ptr2, len2);

    fillArrayByValue(ptr1, len1, 0);
    printArrayByPtr(ptr1, len1);


    fillArrayByRandom(ptr1, len1, 1, 10);
    printArrayByPtr(ptr1, len1);

    free(ptr1);



    return 0;
}
