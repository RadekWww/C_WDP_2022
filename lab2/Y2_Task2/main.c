#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 100
typedef struct box2
{
    int arr[SIZE_MAX];
    int len; //try use size_t
} Box2;

void printBox2(Box2 b){

    printf("printBox2...\n");
    //b.arr[b.len]=222;
    //b.len++;
    for(int i=0; i<b.len; i++ ){

        //printf("%d, ", b.arr[i] );
        printf("%d, ", *(b.arr + i) );
    }
    printf("\n");
    //b.arr[b.len]=333;
    //b.len++;
}

Box2* createBox2(){

    Box2* b = (Box2*) malloc(sizeof(Box2));
    b->len = 0; //(*b).len = 0;


    if(b == NULL)
    {
        printf("memory problem!\n");
        exit(-1);
        return NULL;
    }
    return b;
}

void addAtTheEnd(Box2* b, int val){
    printf("addAtTheEnd..\n");
    if( b->len > SIZE_MAX )
    {
        printf("Box is full!\n");
        return;
    }
    if( b->len == 0 ) printf("Box is Empty!\n");

    b->arr[b->len] = val;
    b->len++;

}

void printBox2ByPtr(Box2* b){

    printf("printBox2ByPtr...\n");

    for(int i=0; i<b->len; i++ ){

        //printf("%d, ", b->arr[i] );
        printf("%d, ", *(b->arr + i) );
    }
    printf("\n");
}


int main()
{
    printf("TASK2!\n");


    Box2 b0;
    printf("sizeof=%d\n", sizeof(b0));

    b0.len=0;
    b0.arr[b0.len]=2;
    b0.len++;
    b0.arr[b0.len]=3;
    b0.len++;
    b0.arr[b0.len]=1;
    b0.len++;

    printBox2(b0);
    printBox2(b0);

    Box2 b1 = { .len = 5, .arr={ 1, 2, 3, 4, 5}  };
    printBox2(b1);

    Box2* b2 = createBox2();

    addAtTheEnd(b2, 1);
    addAtTheEnd(b2, 3);
    addAtTheEnd(b2, 2);
    addAtTheEnd(b2, 8);
    addAtTheEnd(b2, 4);

    printBox2(*b2);
    printBox2ByPtr(b2);


    return 0;
}
