#include <stdio.h>
#include <stdlib.h>

#define SIZE 5     // Maximum array size


void printValue(int val){
    printf("printValue... val:%d\n", val);
}

void setValue(int oldVal, int newVal){
    oldVal = newVal;
    printf("setValue...  oldVal in function after set:%d\n", oldVal);
}

int setValueByReturn(int oldVal, int newVal){
    printf("setValueByReturn...\n");
    oldVal = newVal;
    return oldVal;
    // return newVal;
}

void setValueByPtr(int* oldVal, int newVal){
    printf("setValueByPtr...\n");
    *oldVal = newVal;

}


void printArray(int arr[], int len){
    printf("printArray...\n");
    for(int i=0; i<len; i++){
        printf("[%d]:%d", i, arr[i]);
        if(i<len-1) printf(", ");
        else printf(".");
    }
    printf("\n");
}
void printArrayMix(int arr[], int len){
    printf("printArrayMix1...\n");
    for(int i=0; i<len; i++){
        printf("[%d]:%d, ", i, *(arr+i));
    }
    printf("\n");
}

void printArraByPtrMix(int* arr, int len){
    printf("printArraByPtrMix1...\n");
    for(int i=0; i<len; i++){
        printf("[%d]:%d, ", i, arr[i]);
    }
    printf("\n");
}

void printArraByPtr(int* arr, int len){
    printf("printArraByPtrMix2...\n");
    for(int i=0; i<len; i++){
        printf("[%d]:%d, ", i, *(arr+i) );
    }
    printf("\n");
}


void setArrayValue0123(int arr[], int len){
    printf("setArrayValue0123...\n");
    for(int i=0; i<len; i++){
        arr[i] = i;
    }
}
void setArrayByValue(int arr[], int len, int value){
    printf("setArrayValue0123...\n");
    for(int i=0; i<len; i++){
        arr[i] = value;
    }
}

void addToArray(int arr[], int len, int value){
    printf("addToArray...\n");
    for(int i=0; i<len; i++){
        arr[i] += value;
    }
}

void cacluateStatsOfArray(int* arr, int len, int* sum, int* max, int* min){
    *sum = 0, *max = 0, *min = 0;
    if(len > 0){
        *max = *(arr);
        *min = *(arr);
        for(int i=0; i<len; i++){
            *sum += *(arr+i);
            if(*max < *(arr+i)) *max = *(arr+i);
            if(*min > *(arr+i)) *min = *(arr+i);
        }
    }

}

int* createArray(int n){
    if(n > 0){
        int *arr = (int*)malloc(n*sizeof(int));
        //setArrayByValue(arr, n, 1);
        for(int i=0; i<n; i++){
            *(arr+i) = 0;
        }
        return arr;
    }
    return NULL;
}

void fillArrayRandom(int* arr, int len, int scope){
    srand(time(NULL));
    for(int i=0; i<len; i++){
        *(arr+i) = rand()% scope;
    }
}


void T1_fillArrayRandom(int* arr, int len){
    srand(time(NULL));
    for(int i=0; i<len; i++){
        *(arr+i) = rand();
    }
}

int main()
{
    int a = 5, b = 6,c=7,d =8;
    printValue(a);

    setValue(a,b);
    printValue(a);

    a = setValueByReturn(a,c);
    printValue(a);

    setValueByPtr(&a,d);
    printValue(a);


    printf("Tablice!\n\n");

    //enum enums_size {s = 10};
    //int tab0[s];
    int tab1[SIZE]; //int tab[10];
    int tab2[5] = { 0 };

    int lenTab2 = sizeof(tab2)/sizeof(int);

    //printArray(tab0, s);
    printArray(tab1, SIZE);
    printArray(tab2, lenTab2);

    setArrayValue0123(tab2,lenTab2);
    printArray(tab2, lenTab2);
    printArrayMix(tab2, lenTab2);
    printArraByPtr(tab2, lenTab2);
    printArraByPtrMix(tab2, lenTab2);

    int *ptr;
    ptr = tab2;//lub ptr=&tab2[0];
    printArray(ptr, lenTab2);

    int s, maximum, minimum;
    cacluateStatsOfArray(ptr, lenTab2, &s, &maximum, &minimum);
    printf("suma=%d, maximum=%d, minimum=%d", s, maximum, minimum);

    int n = 5;
    int *arr = (int*)malloc(n*sizeof(int));
    setArrayByValue(arr, n, 1);
    printArray(arr, n);

    int n2 = 6;
    int *arr2 = createArray(n2);
    printArraByPtr(arr2, n2);
    fillArrayRandom(arr2, n2, 10);
    printArraByPtr(arr2, n2);

    t1_fillArrayRandom(arr2, n2);
    printArraByPtr(arr2, n2);

    return 0;
}
