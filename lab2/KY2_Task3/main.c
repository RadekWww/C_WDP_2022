#include <stdio.h>
#include <stdlib.h>

typedef struct box3
{
    int* arr;
    int currentElements; //try use size_t
    char* name;
} Box3;


Box3* createEmptyBox3(char* text)
{

    Box3* ptr = (Box3*)malloc(sizeof(Box3));

    ptr->name = text;
    ptr->currentElements = 0;
    ptr->arr = NULL;

    return ptr;
}

Box3* createOneElmentBox3(char* text, int x)
{
    Box3* ptr = (Box3*)malloc(sizeof(Box3));

    ptr->name = text;
    ptr->currentElements = 1;
    ptr->arr = (int*)malloc(1 * sizeof(int));
    ptr->arr[0] = x;
    *(ptr->arr + 0) = x;


     return ptr;

}

void printArrByPtr(Box3* b)
{
    if( b->currentElements <= 0 )
    {
        printf("arr %s is empty!\n", b->name);
        return;
    }
    printf("arr %s: ", b->name);
    for(int i=0; i< b->currentElements; i++)
    {
        printf("%d ", *(b->arr + i));
        //printf("%d ", b->arr[i]);
    }
    printf("\n");
}

void appendValue(Box3* ptr, int value)
{
    ++(ptr->currentElements);
    int* newptr = (int*)malloc(sizeof(ptr->currentElements));

    int iii;
    for (iii=0; iii < (ptr->currentElements - 1); ++iii)
    {
        newptr[iii] = ptr->arr[iii];
    }
    newptr[iii] = value;
    free(ptr->arr);
    ptr->arr = newptr;

}

void appendValueByRealloc(Box3* ptr, int x)
{
    printf("appendValueByRealloc...\n");
    ++(ptr->currentElements); // b->len += 1;
    ptr->arr = realloc(ptr->arr, ptr->currentElements * sizeof(int));
    *(ptr->arr + (ptr->currentElements - 1) ) = x;
}

void bubbleSort(int *A, int len)
{
    int temp = 0;
    for(int i = 0; i< len-1; i++)
    {
        for(int j = 0; j< len-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void sortBox3(Box3* b)
{
    printf("sortBox3...\n");
    bubbleSort(b->arr, b->currentElements);
}

int main()
{
    printf("T3!\n");

    char nazwa2[] = { 'T', 'e', 's', 't', '\0' };
    char nazwa3[] = "puste pudlo";

    Box3* boxA = createEmptyBox3(nazwa3);
    printf("nazwa %s, liczba elementow: %d\n", boxA->name, boxA->currentElements);


    Box3* boxB =createOneElmentBox3("pudelko B", 3);
    printf("nazwa %s, liczba elementow: %d\n", boxB->name, boxB->currentElements);

    printArrByPtr(boxA);
    printArrByPtr(boxB);

    appendValue(boxB, 2);
    appendValue(boxB, 4);
    printArrByPtr(boxB);

    appendValueByRealloc(boxB, 55);
    printArrByPtr(boxB);

    sortBox3(boxB);
    printArrByPtr(boxB);

    return 0;
}
