#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void printArray(int tab[], int size){
    printf("printArray\n");
    for(int i=0; i<size; i++)
    {
        printf("[%d]=%d, ", i, tab[i]);
    }
    printf("\n");
}

void printArrayByPtr(int* ptrA, int len){
    printf("printArrayByPtr\n");
    for(int i=0; i<len; i++)
    {
        printf("[%d]=%d, ", i, *(ptrA+i) );
    }
    printf("\n");
}


void incrementArray(int* ptrA, int len){
    printf("incrementArray\n");

    *(ptrA+0) += 100;
    //*(ptrA+0) = *(ptrA+0) + 100;

    for(int i=0; i < len; i++){ //i < len  ===  i<=len-1
        printf("%d\n", i);
        if(i % 2 == 0){
            printf("%d jest parzyste\n", i);
        }
        if(len - 1 == i){
            printf("len - 1 == %d", i);
            //A[i] += 100;
            *(ptrA+i) += 100;
        }
    }

    *(ptrA+len-1) += 1000;
}


int* createArray(int len2){

    int* ptr123 = (int*) malloc(len2 * sizeof(int));

    return ptr123;

}

int* createArrayByCalloc(int len2){

    int* ptr123 = (int*) calloc(len2, sizeof(int));

    return ptr123;

}


void setArray(int* ptrA, int len, int value){
    for(int i=0; i < len; i++){
        *(ptrA + i) = value;
    }
}

void setArrayByRandom(int* ptrA, int len, int scope){
    for(int i=0; i < len; i++){
        *(ptrA + i) = (rand() % scope) +1 ;
    }
}


int main()
{
    printf("LAB1 TASK2!aaaa\n");

    enum enums_size {s = 8};

    //int lenTest = 9;

    int A[] = { 1,2,3,4,5,4,3,2,1,0 };

    int* ptrA = &A[0];//A;

    int len = sizeof(A)/sizeof(int);



    printArray(A, len);
    //printArrayByPtr(A, len);
    printArrayByPtr(ptrA, len);
    //printArrayByPtr(&A[0], len);

    //A[0] += 100;
    //A[0] = A[0] + 100;

    incrementArray(ptrA, len);

    printArrayByPtr(ptrA, len);

    int len2 = 6;
    int* ptr = createArray(len2);

    printArrayByPtr(ptr, len2);

    for(int i=0; i < len2; i++){ //i < len  ===  i<=len-1
        *(ptr + i) = 0; // ptr[i]...
    }
    printArrayByPtr(ptr, len2);

    free(ptr);

    int* ptr2 = createArrayByCalloc(len2);
    printArrayByPtr(ptr2, len2);


    setArray(ptr2, len2, 5);
    printArrayByPtr(ptr2, len2);

    setArrayByRandom(ptr2, len2, 10);
    printArrayByPtr(ptr2, len2);

    free(ptr2);

    //free(ptrA);

    return 0;
}
