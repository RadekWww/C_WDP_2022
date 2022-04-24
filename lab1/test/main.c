#include <stdio.h>
#include <stdlib.h>

void zad7(int **a, int **b)
{
    int tymczasowa1;
    int tymczasowa2;

    tymczasowa1 = *a;
    tymczasowa2 = *b;
    *a = tymczasowa2;
    *b = tymczasowa1;
}

void zad7pptr(int **a, int **b)
{
    int tymczasowa1;
    int tymczasowa2;

    tymczasowa1 = **a;
    tymczasowa2 = **b;
    **a = tymczasowa2;
    **b = tymczasowa1;
}

    void t7SwapAdresses(void **ptr1, void **ptr2)
    {
    void *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    }

int main()
{
    printf("Hello world!\n");
    int a=7;
    int b=11;
    int c=19;

    int* wsk_a=&a;
    int* wsk_b=&b;
    int* wsk_c=&c;

    int* wwsk_a=&wsk_a;
    int* wwsk_b=&wsk_b;
    int* wwsk_c=&c;
    printf("a=%d, b=%d\n",wsk_a,wsk_b);
    zad7pptr(&wwsk_a,&wwsk_b);
    printf("a=%d, b=%d\n",wsk_a,wsk_b);

    printf("a=%d, b=%d\n",wsk_a,wsk_b);
    zad7(&wsk_a,&wsk_b);
    printf("a=%d, b=%d\n",wsk_a,wsk_b);

    int *ptra = &a;
        int *ptrb = &b;
    int *ptrc = &c;
                       //Task7
    printf("Task7 Adresy przed zamiana: %p, %p\n", ptra, ptrc);
    t7SwapAdresses(&ptra, &ptrc);
    printf("Task7 Adresy po zamianie: %p, %p\n", ptra, ptrc);

    return 0;
}
