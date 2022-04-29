#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 100
typedef struct box2
{
    int arr[SIZE_MAX];
    int currentElements; //try use size_t
} Box2;

void printBox(Box2 b)
{
    if(b.currentElements <=0 ){
            printf("Box is Empty!\n");
    }
    else
    {
        for(int i= 0; i< b.currentElements; i++)
        {

            //printf("%d, ", b.arr[i]);
            printf("%d, ", *(b.arr + i) );
        }
    printf("%\n");
    }
}
void printBoxByPtr(Box2* box)
{
    if(box->currentElements <=0 ){
            printf("Box is Empty!\n");
    }
    else
    {
        for(int i=0; i< box->currentElements; i++ )
        {

            printf("[%d]=%d, ", i, box->arr[i] );
        }
        printf("\n");
    }

}

void insertEnd(Box2* box, int value)
{
    if(box->currentElements > SIZE_MAX)
    {
        printf("Box is full\n");
        return;
    }

    box->arr[box->currentElements]= value;
    box->currentElements++;


}

Box2* createBox()
{
    printf("sizeof(Box2)=%d\n", sizeof(Box2));

    Box2* b = (Box2*) malloc(sizeof(Box2));
    (*b).currentElements = 0;
    b->currentElements = 0;

    return b;
}

int getNuberOfEven(Box2* box)
{
    int n=0;
    for(int i=0; i<box->currentElements; i++)
    {
        n+=(box->arr[i]) % 2 == 0 ? 1 : 0;

    }
    return n;
}

int main()
{
    printf("TASK2!\n");

    Box2 box;
    box.currentElements = 0;

    box.arr[box.currentElements] = 1;
    box.currentElements++;
    box.arr[box.currentElements] = 33;
    box.currentElements++;
    box.arr[box.currentElements] = 2;
    box.currentElements++;

    printBox(box);

    Box2* ptrBox1 = createBox();

    printBox(*ptrBox1);

    insertEnd(ptrBox1, 1);
    insertEnd(ptrBox1, 2);
    insertEnd(ptrBox1, 33);
    insertEnd(ptrBox1, 1);
    insertEnd(ptrBox1, 4);
    printBox(*ptrBox1);
    printBoxByPtr(ptrBox1);

    int even = getNuberOfEven(ptrBox1);
    printf("even = %d\n", even);

    return 0;
}
