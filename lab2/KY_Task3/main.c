#include <stdio.h>
#include <stdlib.h>

typedef struct box3
{
    int* ptr;
    int len; //try use size_t
    char* name;
} Box3;

Box3* createBox3Empty(char* text )
{
    printf("createBox3Empty...\n");
    Box3* b = (Box3*)malloc(sizeof(Box3));
    b->name = text;
    b->len = 0;
    b->ptr = NULL;
    return b;
}
Box3* createBox3WithOneElement(char* text, int x)
{
    printf("createBox3WithOneElement...\n");
    Box3* b = (Box3*)malloc(sizeof(Box3));
    if(b == NULL)
    {
        printf("memory problem!\n");
        exit(-1);
    }
    b->name = text;
    b->len = 1;
    b->ptr = (int*) malloc(1 * sizeof(int));
    //b->ptr = (int*) calloc(1, sizeof(int));
    *(b->ptr) = x;
    return b;
}



void printBox3ByPtr(Box3* b){

    printf("printBox3ByPtr...\n");
    if(b->len <= 0)
    {
        printf("Box3 %s is Empty!\n", b->name);
    }
    else
    {
        printf("Box3 %s is :", b->name);
        for(int i=0; i< b->len;i++)
        {
            printf("%d", *(b->ptr+i) );
            if(i<b->len - 1) printf(", ");
            else printf("\n");
        }
    }
}

void addXToBox3AtEnd(Box3* b, int x)
{
    printf("addXToBox3AtEnd...\n");

    int oldLen = b->len;
    int newLen = oldLen +1;

    int *p = (int*) calloc(newLen, sizeof(int));
    for(int i= 0; i< oldLen; i++)
    {
        *(p+i) = *(b->ptr + i);
    }
    *(p+newLen -1) = x;
    free(b->ptr);
    b->ptr = p;
    b->len = newLen;
}

void addXToBox3AtEndByRealloc(Box3* b, int x)
{
    printf("addXToBox3AtEndByRealloc...\n");
    b->len += 1;
    b->ptr = realloc(b->ptr, b->len * sizeof(int));
    *(b->ptr + (b->len-1) ) = x;
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
    bubbleSort(b->ptr, b->len);
}



int main()
{
    printf("Task3\n");


    Box3* box0 = createBox3Empty("Pudelko 0");
    Box3* box1 = createBox3WithOneElement("Pudelko 1", 1);

    int*ptr;

    printBox3ByPtr(box0);
    printBox3ByPtr(box1);

    addXToBox3AtEnd(box0, 1);
    addXToBox3AtEnd(box0, 3);
    addXToBox3AtEnd(box0, 2);
    printBox3ByPtr(box0);

    addXToBox3AtEnd(box1, 11);
    addXToBox3AtEnd(box1, 31);
    addXToBox3AtEnd(box1, 21);
    addXToBox3AtEndByRealloc(box1, 121);
    addXToBox3AtEndByRealloc(box1, 4);
    printBox3ByPtr(box1);

    sortBox3(box1);
    printBox3ByPtr(box1);


    return 0;
}
