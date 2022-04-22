#include <stdio.h>
#include <stdlib.h>


int addXtoY(int x, int y){
    x = x + y;
    return x;
}

void addXPtr(int* value, int x){
    *value += x;
}


int main()
{
    printf("Task1!\n");


    int a;
    int* ptr;

    a=1;
    ptr = &a;

    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d %p\n", &a, &a);
    printf("wskaznik  czyli adres %d %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d %p\n", &ptr, &ptr);
    printf("\n");

    a = a +2;
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d %p\n", &a, &a);
    printf("wskaznik  czyli adres %d %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d %p\n", &ptr, &ptr);
    printf("\n");

    *ptr = *ptr + 4; //ptr =  ptr + 4;
    *ptr += 2;
    (*ptr)++;
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d %p\n", &a, &a);
    printf("wskaznik  czyli adres %d %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d %p\n", &ptr, &ptr);
    printf("\n");

    a = addXtoY(a, 2);
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d %p\n", &a, &a);
    printf("wskaznik  czyli adres %d %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d %p\n", &ptr, &ptr);
    printf("\n");

    addXPtr(&a, 3);
    addXPtr(ptr, 3);
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d %p\n", &a, &a);
    printf("wskaznik  czyli adres %d %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d %p\n", &ptr, &ptr);
    printf("\n");

    int** pptr;
    pptr = &ptr;
    printf("**pptr = %d, *ptr = %d \n", **pptr, *ptr);

    return 0;
}
