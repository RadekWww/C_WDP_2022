#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 10

typedef struct box2
{
    int arr[SIZE_MAX];
    int len; //try use size_t
} Box2;


void addXToBox2(Box2* b, int x)
{
    printf("addXToBox2ByPtr...\n");
    if(b->len  < SIZE_MAX){
        *(b->arr + b->len) = x; //b->arr[b->len] = x;
        (b->len)++;
    }
    else printf("SIZE_MAX\n");
}

void printBox2(Box2 b){

    printf("printBox2...\n");
    if(b.len <= 0)
    {
        printf("Box2 is Empty!\n");
    }
    else
    {
        for(int i=0; i<b.len;i++)
        {
            printf("%d", *(b.arr+i) );
            if(i<b.len - 1) printf(", ");
            else printf("\n");
        }
    }
}

void printBox2ByPtr(Box2* b){

    printf("printBox2ByPtr...\n");
    if(b->len <= 0)
    {
        printf("Box2 is Empty!\n");
    }
    else
    {
        for(int i=0; i<b->len;i++)
        {
            printf("%d", *(b->arr+i) );
            if(i<b->len - 1) printf(", ");
            else printf("\n");
        }
    }
}

Box2* createBox2(){
    printf("createBox2...\n");
    Box2* b = (Box2*)malloc(sizeof(Box2));
    b->len = 0;

    if(b == NULL)
    {
        printf("memory problem!\n");
        exit(-1);
    }
    return b;
}

int getAndPrintEvenNumberFromBox2(Box2 b)
{
    printf("getAndPrintEvenNumberFromBox2...\n");
    int evenNumber = 0;
    for(int i=0; i<b.len;i++)
    {
        if(*(b.arr + i) % 2 == 0 )
        {
            evenNumber++;
        }
    }
    printf("evenNumber=%d\n", evenNumber);
    return evenNumber;
}


int main()
{
    printf("TASK2!\n");

    Box2 box0;
    box0.len = 0;

    Box2 box1 = { .arr= { 0 }, .len= 5 };


    addXToBox2(&box0, 1);
    addXToBox2(&box0, 4);
    addXToBox2(&box0, 3);
    addXToBox2(&box0, 2);

    box0.arr[box0.len] = 7;
    box0.len++;

    printBox2(box0);
    addXToBox2(&box1, 66);
    printBox2(box1);

    Box2* pBox0 = createBox2();
    printBox2(*pBox0);

    addXToBox2(pBox0, 1);
    addXToBox2(pBox0, 3);
    addXToBox2(pBox0, 2);
    addXToBox2(pBox0, 1);
    printBox2ByPtr(pBox0);

    getAndPrintEvenNumberFromBox2(*pBox0);





    return 0;
}
