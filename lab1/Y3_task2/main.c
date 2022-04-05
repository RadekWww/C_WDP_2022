#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


void printArray(int tab[], int len)
{
    printf("printArray...\n");
    if(len > 0)
    {
        for(int i=0; i< len; i++){
            printf("[%d]=%d, ", i, tab[i]);
        }
        printf("\n");
    }
}

void printArrayByPtr(int* tab, int len)
{
    printf("printArrayByPtr...\n");
    if(len > 0)
    {
        for(int i=0; i< len; i++){
            printf("[%d]=%d, ", i, *(tab+i) );
        }
        printf("\n");
    }
}

void incElementOfArrayByPtr(int* tab, int len)
{
    printf("incElementOfArrayByPtr...\n");
    if(len > 0)
    {
        *(tab) += 100; // tab[0]
        *(tab+len-1) += 100; //tab[len-1]
    }
}

int* createArrayByMalloc(int len){
    printf("createArrayByMalloc...\n");
    int *ptr = (int *) malloc(len * sizeof(int));
    return ptr;
}

int* createArrayByCalloc(int len){
    printf("createArrayByCalloc...\n");
    int *ptr =  (int*)calloc(len, sizeof(int));
    return ptr;
}

void fillArrayByValue(int* tab, int len, int value)
{
    printf("fillArrayByValue...\n");
    if(len > 0)
    {
        for(int i=0; i< len; i++){
            *(tab+i) = value;
        }
    }
}

void fillArrayByRandom(int* tab, int len, int scope)
{
    printf("fillArrayByRandom...\n");
    if(len > 0)
    {
        srand(time(NULL));
        for(int i=0; i< len; i++){
            *(tab+i) = rand() % scope;
        }
    }
}

int main()
{
    printf("Task2!\n");


    int B[SIZE];// = { 0 };
    int A[] = { 0,1,2,3,4,5,6,7,8,9 };

    int* ptrA = A; // &A[0];

    int len = sizeof(A)/sizeof(int);

    printArray(A, len);
    printArrayByPtr(ptrA, len);
    printArrayByPtr(A, len);

    printf("\n");
    incElementOfArrayByPtr(ptrA, len);
    printArrayByPtr(ptrA, len);

    int len2=5;
    int* tab = createArrayByMalloc(len2);
    printArrayByPtr(tab, len2);
    printArray(B, len);
    printf("TEST START!\n");
    int* tab2 = createArrayByCalloc(len2);
    printArrayByPtr(tab2, len2);
    free(tab2);
    printArrayByPtr(tab2, len2);
    printf("TEST END!\n");
    fillArrayByValue(tab, len2, 1);
    printArrayByPtr(tab, len2);

    fillArrayByRandom(tab, len2, 100);
    printArrayByPtr(tab, len2);

    free(tab);
    free(A);


    return 0;
}
