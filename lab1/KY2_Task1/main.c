#include <stdio.h>
#include <stdlib.h>

int addX(int value, int x){
    int result = value + x;
    return result;
}

void addYByPtr(int* value2, int y){
    *value2 += y;
}

int main()
{
    printf("Task1\n");

    int a;
    int* ptr;

    a = 1;
    ptr = &a;

    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaznik %d, %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d, %p\n", &ptr, &ptr);
    printf("\n");

    a += 2;
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaznik %d, %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d, %p\n", &ptr, &ptr);
    printf("\n");

    //ptr =  ptr + 4;
    *ptr =  *ptr + 4;
    *ptr += 1;
    (*ptr)++; // *ptr++ <=> ptr = ptr + 1
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaznik %d, %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d, %p\n", &ptr, &ptr);
    printf("\n");

    a = addX(a, 5);
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaznik %d, %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d, %p\n", &ptr, &ptr);
    printf("\n");

    addYByPtr(ptr, 1);
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaznik %d, %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d, %p\n", &ptr, &ptr);
    printf("\n");

    addYByPtr(&a, 1);
    printf("wartosc zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaznik %d, %p\n", ptr, ptr);
    printf("wartosc wskazywana przez wskaznik %d\n", *ptr);
    printf("adres wskaznika %d, %p\n", &ptr, &ptr);
    printf("\n");

    int** pptr;
    pptr = &ptr;
    printf("**pptr = %d, *ptr = %d \n", **pptr, *ptr);

    return 0;
}
