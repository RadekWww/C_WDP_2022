#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void printArray(int A[], int lenTab)
{
    printf("printArray\n");
    for(int i=0; i< lenTab; i++)
    {
        printf("[%d]=%d, ", i, A[i]);
    }
    printf("\n");
}

void printArrayByPtr(int* ptrA, int lenTab)
{
    printf("printArrayByPtr\n");
    for(int i=0; i< lenTab; i++)
    {
        printf("[%d]=%d, ", i, *(ptrA+i));
    }
    printf("\n");
}

void incrementFirstAndLastElementOfArray(int* ptrA, int lenTab)
{
    printf("IncrementFirstAndLastElementOfArray\n");
    if(lenTab>0){
        *(ptrA) += 100;
        *(ptrA + lenTab - 1) += 100;
    }

}

int* createArrayByMA(int len)
{

    int* ptr = (int*) malloc(len * sizeof(int));
    printf("createArrayByMA: %p\n", ptr);
    return ptr;
}

int* createArrayByCA(int len)
{

    int* ptr = (int*) calloc(len, sizeof(int));
    printf("createArrayByCA: %p\n", ptr);
    return ptr;
}

void fillArray(int* ptr, int len, int value)
{
    printf("fillArray: %p\n", ptr);
    for(int i=0; i< len; i++)
    {
        *(ptr+i) = value;
    }
}

void fillArrayRandomValue(int* ptr, int len, int scope)
{
    printf("fillArrayRandomValue: %p\n", ptr);
    for(int i=0; i< len; i++)
    {
        *(ptr+i) = rand() % scope;
    }
}


int main()
{
    printf("Task2!\n");

    enum enums_size {s = 8};
    int B[SIZE];
    int C[SIZE] = { 0 };
    int D[s];

    int A[] = { 0,1,2,3,4,5,6,7 };

    int lenTab = sizeof(A)/sizeof(int);

    int* ptrA = A; // &A[0]
    int* ptrX = NULL;


    printArray(A, lenTab);
    printArrayByPtr(ptrA, lenTab);

    incrementFirstAndLastElementOfArray(ptrA, lenTab);
    printArrayByPtr(ptrA, lenTab);

    //free(ptrA); //tablica utworzona na stosie, sposób statyczny

    int len = 5;
    int* ptr = createArrayByMA(len);
    printArrayByPtr(ptr, len);

    int* ptr2 = createArrayByCA(len);
    printArrayByPtr(ptr2, len);

    free(ptr2);

    fillArray(ptr, len, 1);
    printArrayByPtr(ptr, len);

    fillArrayRandomValue(ptr, len, 150);
    printArrayByPtr(ptr, len);
    free(ptr);


    return 0;
}
