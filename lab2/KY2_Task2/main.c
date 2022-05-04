#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX_ARR 100
typedef struct box2
{
    int arr[SIZE_MAX_ARR];
    int currentElements; //try use size_t
} Box2;


void printArr(Box2 b)
{
    if(b.currentElements <= 0)
    {
        printf("Arr is Empty!\n");
        return;
    }

    for(int i=0; i< b.currentElements; i++)
    {
        //printf("*%d ", b.arr[i]);
        printf("%d ", *(b.arr + i) );
    }
    printf("\n");
}


void printArrByPtr(Box2* b)
{


    for(int i=0; i< b->currentElements; i++)
    {
        printf("%d ", *(b->arr + i));
        //printf("%d ", b->arr[i]);
    }
    printf("\n");
}

Box2* createBox2(){

    Box2* ptr = (Box2*) malloc(1 * sizeof(Box2));
    //(*ptr).currentElements = 0;
    ptr->currentElements = 0;
    return ptr;
}

void addXToBox2(Box2* b, int x)
{
    if(b->currentElements < SIZE_MAX_ARR)
    {
        *(b->arr + b->currentElements) = x;
        b->currentElements++;
    }

}

int main()
{
    printf("T2!\n");

    Box2 boxA;
    boxA.arr;
    boxA.currentElements = 0;

    boxA.arr[boxA.currentElements] = 4;
    boxA.currentElements++;
    boxA.arr[boxA.currentElements] = 2;
    boxA.currentElements++;
    boxA.arr[boxA.currentElements] = 3;
    boxA.currentElements++;
    boxA.arr[boxA.currentElements] = 5;
    boxA.currentElements++;
    printArr(boxA);


    Box2* boxB = createBox2();
    printArr(*boxB);

    addXToBox2(boxB, 4);
    addXToBox2(boxB, 2);
    addXToBox2(boxB, 3);
    printArr(*boxB);

    printArrByPtr(boxB);

    return 0;
}
