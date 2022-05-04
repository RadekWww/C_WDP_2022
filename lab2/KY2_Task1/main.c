#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX_ARR 100


void addXtoArr(int* arr, int* currentElements, int x)
{
    if( *currentElements < SIZE_MAX_ARR )
    {
        *(arr + *currentElements) = x;
        (*currentElements)++;
    }
}

void printArr(int* arr, int currentElements )
{

    for(int i=0; i< currentElements; i++)
    {
        //printf("%d ", arr[i]);
        printf("%d ", *(arr + i) );
    }
    printf("\n");
}

void wipeArr(int* arr, int* currentElements)
{
    for(int i=0; i< *currentElements; i++)
    {
        arr[i] = 0;
    }
    *currentElements = 0;
}

int getMaxAndPrint(int* arr, int currentElements)
{
    if(currentElements <= 0 )
        return INT_MIN;

    int max = *(arr + 0 );
    //int max = INT_MIN;
    for(int i = 1; i < currentElements; i++)
    {
        if( *(arr + i) > max )
        {
            max = *(arr + i);
        }
    }
    printf("max = %d\n", max);
    return max;
}

void deleteX(int * arr, int* currentElements, int x)
{
    int i;
    for(i = 0; *(arr+i) !=x && i < (*currentElements) ; i++)
    {

    }

    for(int j = i; j< (*currentElements) - 1; j++)
    {
        *(arr + j) = *(arr + j +1);
    }
    if (i < (*currentElements))
    {
        *(arr + *currentElements) = 0;
        (*currentElements)--;
    }

}
void deleteElement(int* arr, int* len, int val){

    if(*len <=0 ){
        printf("arr is Empty!\n");
        return;
    }
    for(int i = 0; i< *len; i++){
        if( *(arr+i) == val  ){

            for(int j = i; j < *len -1; j++){

                *(arr+j) = *(arr+j+1);
            }
            (*len)--;
            printf("delete %d\n", val);
            return;
        }
    }
}


int main()
{
    printf("T1!\n");

    int arr[SIZE_MAX_ARR] = { 0 };
    int currentElements= 0;

    addXtoArr(arr, &currentElements, 4);
    addXtoArr(arr, &currentElements, 2);
    addXtoArr(arr, &currentElements, 3);
    addXtoArr(arr, &currentElements, 5);

    printArr(arr, currentElements);
    printf("currentElements=%d\n", currentElements );

    wipeArr(arr, &currentElements);
    printArr(arr, currentElements);
    printf("currentElements=%d\n", currentElements );

    addXtoArr(arr, &currentElements, 4);
    addXtoArr(arr, &currentElements, 2);
    addXtoArr(arr, &currentElements, 33);
    addXtoArr(arr, &currentElements, 33);
    addXtoArr(arr, &currentElements, 5);
    printArr(arr, currentElements);

    int max = getMaxAndPrint(arr, currentElements);

    deleteX(arr, &currentElements, max);
    printArr(arr, currentElements);

    max = getMaxAndPrint(arr, currentElements);

    deleteX(arr, &currentElements, max);
    printArr(arr, currentElements);

    max = getMaxAndPrint(arr, currentElements);

    deleteX(arr, &currentElements, max);
    printArr(arr, currentElements);
        max = getMaxAndPrint(arr, currentElements);

    deleteX(arr, &currentElements, max);
    printArr(arr, currentElements);
        max = getMaxAndPrint(arr, currentElements);

    deleteX(arr, &currentElements, max);
    printArr(arr, currentElements);

    max = getMaxAndPrint(arr, currentElements);
    printf("max = %d\n", max);

    return 0;
}
