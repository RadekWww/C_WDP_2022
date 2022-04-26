#include <stdio.h>
#include <stdlib.h>

typedef struct box3
{
    int* ptr;
    int len; //try use size_t
    char* name;
} Box3;


Box3* createBox3Empty(char* text){

    Box3* b = (Box3*) malloc(sizeof(Box3));
    //printf("sizeof=%d\n", sizeof(b));
    b->len = 0; //(*b).len = 0;
    b->ptr = NULL;
    b->name = text;

    return b;
}

Box3* createBox3WithOneElement(char* text, int value){

    Box3* b = (Box3*) malloc(sizeof(Box3));
    b->len = 0; //(*b).len = 0;
    b->ptr = (int*) malloc(sizeof(int));
    *(b->ptr) = value;
    b->name = text;

    //printf("sizeof(b)=%d\n", sizeof(b));
    //printf("sizeof(b->ptr)=%d\n", sizeof(b->ptr));
    return b;
}


void addAtTheEnd(Box3* b, int val){
    printf("addAtTheEnd.. %s\n", b->name);
    if( b->len == 0 ) printf("Box %s is Empty!\n", b->name);

    b->len++;
    b->ptr = realloc(b->ptr, (b->len) * sizeof(int) );

    //b->ptr[b->len-1] = val;
    *(b->ptr + b->len-1) = val;


}

void printBox3ByPtr(Box3* b){

    printf("printBox3ByPtr...%s\n", b->name);

    for(int i=0; i< b->len; i++ ){

        //printf("%d, ", b->arr[i] );
        printf("%d, ", *(b->ptr + i) );
    }
    printf("\n");
}

void bubble_sort(int a[], int n) {
    int i = 0, j = 0, tmp;
    for (i = 0; i < n - 1; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (a[j] > a[j + 1]) {  // swop if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void mySort(Box3* b){
    printf("mySort...%s\n", b->name);
    bubble_sort(b->ptr, b->len);
}

int main()
{
    printf("TASK3!\n");

    Box3* b0 = createBox3Empty("pudelko nr 0");
    Box3* b1 = createBox3WithOneElement("pudelko nr 1", 10);

    addAtTheEnd(b0, 1);
    addAtTheEnd(b0, 22);
    addAtTheEnd(b0, 3);

    addAtTheEnd(b1, 11);
    addAtTheEnd(b1, 12);
    addAtTheEnd(b1, 5);
    addAtTheEnd(b1, 112);
    addAtTheEnd(b1, 5);

    printBox3ByPtr(b0);
    printBox3ByPtr(b1);

    mySort(b0);
    printBox3ByPtr(b0);

    mySort(b1);
    printBox3ByPtr(b1);
    addAtTheEnd(b1, 1);
    mySort(b1);
    printBox3ByPtr(b1);



    return 0;
}
