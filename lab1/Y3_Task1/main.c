#include <stdio.h>
#include <stdlib.h>


int addX(int b, int x){
    int ret = b + x;
    return ret;
}

void addXByPtr(int* b, int x){

    *b = *b + x; //*b += x;
}


int main()
{
    printf("Task1!\n");

    int a;
    int* ptr;

    a = 10;
    ptr = &a;

    printf("warto�� zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wska�nik  %d\n", ptr);
    printf("warto�� wskazywana przez wska�nik %d\n", *ptr);
    printf("adres wska�nika %d\n", &ptr);
    printf("\n");

    a = a +2;
    printf("warto�� zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wska�nik  %d\n", ptr);
    printf("warto�� wskazywana przez wska�nik %d\n", *ptr);
    printf("adres wska�nika %d\n", &ptr);
    printf("\n");

    *ptr = *ptr + 4;
    *ptr += 4;
    (*ptr)++;
    ++*ptr;
    printf("warto�� zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wska�nik  %d\n", ptr);
    printf("warto�� wskazywana przez wska�nik %d\n", *ptr);
    printf("adres wska�nika %d\n", &ptr);
    printf("\n");

    a = addX(a, 100);
    printf("warto�� zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wska�nik  %d\n", ptr);
    printf("warto�� wskazywana przez wska�nik %d\n", *ptr);
    printf("adres wska�nika %d\n", &ptr);
    printf("\n");

    addXByPtr(&a, 1000);
    printf("warto�� zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wska�nik  %d\n", ptr);
    printf("warto�� wskazywana przez wska�nik %d\n", *ptr);
    printf("adres wska�nika %d\n", &ptr);
    printf("\n");

    addXByPtr(ptr, 2000);
    printf("warto�� zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wska�nik  %d\n", ptr);
    printf("warto�� wskazywana przez wska�nik %d\n", *ptr);
    printf("adres wska�nika %d\n", &ptr);
    printf("\n");


    return 0;
}
