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

    printf("wartoœæ zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaŸnik  %d\n", ptr);
    printf("wartoœæ wskazywana przez wskaŸnik %d\n", *ptr);
    printf("adres wskaŸnika %d\n", &ptr);
    printf("\n");

    a = a +2;
    printf("wartoœæ zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaŸnik  %d\n", ptr);
    printf("wartoœæ wskazywana przez wskaŸnik %d\n", *ptr);
    printf("adres wskaŸnika %d\n", &ptr);
    printf("\n");

    *ptr = *ptr + 4;
    *ptr += 4;
    (*ptr)++;
    ++*ptr;
    printf("wartoœæ zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaŸnik  %d\n", ptr);
    printf("wartoœæ wskazywana przez wskaŸnik %d\n", *ptr);
    printf("adres wskaŸnika %d\n", &ptr);
    printf("\n");

    a = addX(a, 100);
    printf("wartoœæ zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaŸnik  %d\n", ptr);
    printf("wartoœæ wskazywana przez wskaŸnik %d\n", *ptr);
    printf("adres wskaŸnika %d\n", &ptr);
    printf("\n");

    addXByPtr(&a, 1000);
    printf("wartoœæ zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaŸnik  %d\n", ptr);
    printf("wartoœæ wskazywana przez wskaŸnik %d\n", *ptr);
    printf("adres wskaŸnika %d\n", &ptr);
    printf("\n");

    addXByPtr(ptr, 2000);
    printf("wartoœæ zmiennej %d\n", a);
    printf("adres zmiennej %d, %p\n", &a, &a);
    printf("wskaŸnik  %d\n", ptr);
    printf("wartoœæ wskazywana przez wskaŸnik %d\n", *ptr);
    printf("adres wskaŸnika %d\n", &ptr);
    printf("\n");


    return 0;
}
