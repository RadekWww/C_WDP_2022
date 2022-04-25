#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAX 100


void addXToArr(int arr[], int* len, int x)
{
    printf("addXToArr...\n");
    if(*len < SIZE_MAX){
        arr[*len] = x;
        (*len)++;
    }
    else printf("SIZE_MAX\n");
}

void addXToArrByPtr(int* arr, int* len, int x)
{
    printf("addXToArrByPtr...\n");
    if(*len < SIZE_MAX){
        *(arr + *len) = x;
        (*len)++;
    }
    else printf("SIZE_MAX\n");
}

void printfArr(int* arr, int len){

    printf("printfArr...\n");
    if(len <= 0)
    {
        printf("Arr is Empty!\n");
    }
    else
    {
        for(int i=0; i<len;i++)
        {
            printf("%d", *(arr+i) );
            if(i<len - 1) printf(", ");
            else printf("\n");
        }
    }
}

void clearArr(int* arr, int* len)
{
    printf("clearArr...\n");
    for(int i=0; i< *len;i++)
    {
        *(arr + i) = 0;
    }
    *len = 0;
}

int getAndPrintMax(int* arr, int len){

    printf("getAndPrintMax...\n");
    if(len <= 0)
    {
        printf("Arr is Empty!\n");
        return INT_MIN;
    }
    else
    {
        int max = *arr;
        for(int i=1; i<len;i++)
        {
            if( *(arr+i) > max  )
            {
                max = *(arr+i);
            }
        }
        printf("Max is:%d\n", max);
        return max;
    }
}

void deleteXForArr(int* arr, int* len, int x)
{
    printf("deleteXForArr...\n");
    if(*len <= 0)
    {
        printf("Arr is Empty!\n");
        return;
    }
    //szukanie czy x wystepuje w tablicy
    int indexToDelete = -1;
    for(int i = 0; i< *len; i++)
    {
        if( *(arr+i) == x ){
            indexToDelete = i;
            break;
        }
    }
    //jezeli nie ma x to konczymy
    if(indexToDelete == -1)
    {
        printf("X=%d is not exist!\n", x);
        return;
    }
    // tablica jest 1 elementowa
    if(*len == 1)
    {
        *arr = 0;
        *len = 0;
        return;
    }
    //x jest ostatnim elementem tablicy
    if(indexToDelete == (*len - 1) )
    {
        *(arr + indexToDelete) = 0;
        *len -= 1;
        return;
    }

    int newSize = *len -1;
    int temp[newSize];

    for(int i =0; i < indexToDelete; i++)
    {
        temp[i] = *(arr+i);
    }
    for(int i =indexToDelete +1 ; i < *len; i++)
    {
        temp[i-1] = *(arr+i);
    }
    *len -= 1;
    *(arr + *len) = 0;
    for(int i=0; i< *len; i++)
    {
        *(arr+i) = temp[i];
    }
}




int main()
{
    printf("Task1!\n");

    int arr[SIZE_MAX];
    int len = 0; //try use size_t

    //a
    addXToArr(arr, &len, 1);
    addXToArrByPtr(arr, &len, 20);
    addXToArr(arr, &len, 3);

    //b
    printfArr(arr,len);

    //d
    clearArr(arr, &len);
    printfArr(arr,len);

    //e
    addXToArrByPtr(arr, &len, -5);
    addXToArrByPtr(arr, &len, 22);
    addXToArrByPtr(arr, &len, 44);
    addXToArrByPtr(arr, &len, 5);
    printfArr(arr,len);
    getAndPrintMax(arr, len);

    deleteXForArr(arr, &len, 2);
    deleteXForArr(arr, &len, 22);
    printfArr(arr,len);

    deleteXForArr(arr, &len, 5);
    printfArr(arr,len);
    deleteXForArr(arr, &len, -5);
    printfArr(arr,len);
    deleteXForArr(arr, &len, 44);
    printfArr(arr,len);


    return 0;
}
