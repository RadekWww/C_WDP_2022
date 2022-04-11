#include <stdio.h>
#include <stdlib.h>

int addX(int, int);

void addXByPtr(int* value, int increment)
{
    *value += increment;

}

int main()
{
    printf("Task1!\n");

    int a;
    int* ptr;

    a = 5;
    ptr = &a;

    printf("wartosc zmiennej: %d\n", a);
    printf("adres  zmiennej: %d\n", &a);
    printf("wskaznik: %d\n", ptr); //%p
    printf("wartosc wskazywana przez  wskaznik: %d\n", *ptr); //%p
    printf("adres wskaznika: %d\n", &ptr);
    printf("\n");

    a = a+2;
    printf("wartosc zmiennej: %d\n", a);
    printf("adres  zmiennej: %d\n", &a);
    printf("wskaznik: %d\n", ptr); //%p
    printf("wartosc wskazywana przez  wskaznik: %d\n", *ptr); //%p
    printf("adres wskaznika: %d\n", &ptr);
    printf("\n");

    *ptr = *ptr + 2;
    *ptr += 1;
    (*ptr)++; // *ptr++ <=> ptr = ptr + 1
    printf("wartosc zmiennej: %d\n", a);
    printf("adres  zmiennej: %d\n", &a);
    printf("wskaznik: %d\n", ptr); //%p
    printf("wartosc wskazywana przez  wskaznik: %d\n", *ptr); //%p
    printf("adres wskaznika: %d\n", &ptr);
    printf("\n");

    a = addX(a, 2);
    printf("wartosc zmiennej: %d\n", a);
    printf("adres  zmiennej: %d\n", &a);
    printf("wskaznik: %d\n", ptr); //%p
    printf("wartosc wskazywana przez  wskaznik: %d\n", *ptr); //%p
    printf("adres wskaznika: %d\n", &ptr);
    printf("\n");

    addXByPtr(&a, 4);
    printf("wartosc zmiennej: %d\n", a);
    printf("adres  zmiennej: %d\n", &a);
    printf("wskaznik: %d\n", ptr); //%p
    printf("wartosc wskazywana przez  wskaznik: %d\n", *ptr); //%p
    printf("adres wskaznika: %d\n", &ptr);
    printf("\n");

    addXByPtr(ptr, 4);
    printf("wartosc zmiennej: %d\n", a);
    printf("adres  zmiennej: %d\n", &a);
    printf("wskaznik: %d\n", ptr); //%p
    printf("wartosc wskazywana przez  wskaznik: %d\n", *ptr); //%p
    printf("adres wskaznika: %p\n", &ptr);
    printf("\n");

    int  **pptr;
    pptr = &ptr;
    printf("**pptr = %d, *ptr = %d \n", **pptr, *ptr);

    return 0;
}

int addX(int a, int x){
    int result = a + x;
    return result;
}
