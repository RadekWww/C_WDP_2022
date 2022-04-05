#include <stdio.h>
#include <stdlib.h>



void swap_nums(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}


void swap2 (int **pa, int **pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    printf("Hello world!\n");


    int a1 = 3, b1 = 5;
    int * ptrA = &a1;
    int * ptrB = &b1;
    printf("%p %p %p %p\n", &a1, &b1, ptrA, ptrB);
    printf("Liczby po zamianie [a]: %d, [b]: %d\n", *ptrA, *ptrB);
    printf("Liczby po zamianie [a]: %d, [b]: %d\n", a1, b1);
    //tSwapP(ptrA, ptrB);

    swap2(ptrA, ptrB);


    printf("%p %p %p %p\n", &a1, &b1, ptrA, ptrB);
    printf("Liczby po zamianie [a]: %d, [b]: %d\n", *ptrA, *ptrB);
    printf("Liczby po zamianie [a]: %d, [b]: %d\n", a1, b1);




    return 0;
}


