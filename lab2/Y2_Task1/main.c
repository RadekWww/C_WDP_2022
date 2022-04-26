#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAX 100

void addValueToBox1(int* arr, int* len, int value){
    printf("addValueToBox1\n");
    *(arr + *len) = value; // arr[*len] = value;
    *len += 1;
}

void printArr(int* arr, int len)
{
    printf("printArr\n");
    if(len <=0 ){
        printf("arr is Empty!\n");
        return;
    }
    for(int i = 0; i< len; i++){
        printf("%i", arr[i]);
        if(i < len - 1) printf(", ");
        else printf("\n");
    }
}

void clearArr(int* arr, int* len){
    printf("clearArr\n");
    *len = 0;
    for(int i = 0; i< *len; i++){
        *(arr + *len) = 0;
    }
}

int getAndPrintMax(int* arr, int len)
{
    printf("getAndPrintMax\n");
    if(len <=0 ){
        printf("arr is Empty!\n");
        return;
    }
    int max = INT_MIN;
    for(int i = 0; i< len; i++){
        if(max < *(arr + i)) max = *(arr + i);
    }
    printf("max=%d\n", max);
    return max;
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

void deleteXForArr(int*, int*, int);




int main()
{
    printf("Task1!\n");


    int arr[SIZE_MAX] ={ 0 };
    int len = 0; //try use size_t


    addValueToBox1(arr, &len, 1);
    addValueToBox1(arr, &len, 3);
    addValueToBox1(arr, &len, 2);

    printArr(arr, len);

    clearArr(arr, &len);
    printArr(arr, len);

    addValueToBox1(arr, &len, 1);
    addValueToBox1(arr, &len, 3);
    addValueToBox1(arr, &len, 2);
    addValueToBox1(arr, &len, 12);
    //addValueToBox1(arr, &len, INT_MAX);
    addValueToBox1(arr, &len, 2);

    getAndPrintMax(arr, len);
    printArr(arr, len);
    deleteElement(arr, &len, 0);
    deleteElement(arr, &len, 2);
    deleteElement(arr, &len, 3);
    deleteElement(arr, &len, 1);
    deleteElement(arr, &len, 12);
    deleteElement(arr, &len, 2);

    printArr(arr, len);



    return 0;
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
