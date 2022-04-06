#include <stdio.h>
#include <stdlib.h>

int addX(int b, int z)
{
    return b+z;
}

void addXByPtr(int* ptr, int value){

    *ptr += value;
}



int main()
{
    printf("Task1!\n");

    int a;
    int* ptr;

    a = 1;
    ptr = &a;

    printf("wartosc zmiennej: %d\n", a);
    printf("adres zmiennej: %p\n", &a);
    printf("wskaznik:  %p\n", ptr);
    printf("wartosc wskazywana przez wskaznik:  %d\n", *ptr);
    printf("adres wskaznika:  %p\n", &ptr);
    printf("\n");

    a = a +2;
    printf("wartosc zmiennej: %d\n", a);
    printf("adres zmiennej: %p\n", &a);
    printf("wskaznik:  %p\n", ptr);
    printf("wartosc wskazywana przez wskaznik:  %d\n", *ptr);
    printf("adres wskaznika:  %p\n", &ptr);
    printf("\n");

    *ptr = *ptr + 4;
    *ptr += 1;
    (*ptr)++;
    printf("wartosc zmiennej: %d\n", a);
    printf("adres zmiennej: %p\n", &a);
    printf("wskaznik:  %p\n", ptr);
    printf("wartosc wskazywana przez wskaznik:  %d\n", *ptr);
    printf("adres wskaznika:  %p\n", &ptr);
    printf("\n");

    a = addX(a, 1);
    printf("wartosc zmiennej: %d\n", a);
    printf("adres zmiennej: %p\n", &a);
    printf("wskaznik:  %p\n", ptr);
    printf("wartosc wskazywana przez wskaznik:  %d\n", *ptr);
    printf("adres wskaznika:  %p\n", &ptr);
    printf("\n");


    addXByPtr(&a, 10);
    addXByPtr(ptr, 100);
    printf("wartosc zmiennej: %d\n", a);
    printf("adres zmiennej: %p\n", &a);
    printf("wskaznik:  %p\n", ptr);
    printf("wartosc wskazywana przez wskaznik:  %d\n", *ptr);
    printf("adres wskaznika:  %p\n", &ptr);
    printf("\n");

    return 0;
}
