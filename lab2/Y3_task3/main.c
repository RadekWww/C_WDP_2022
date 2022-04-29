#include <stdio.h>
#include <stdlib.h>


typedef struct box3
{
    int* ptr;
    int len; //try use size_t
    char* name;
} Box3;

Box3* createBox3(char* text)
{
    //printf("sizeof(Box3)=%d\n", sizeof(Box3));
    Box3* ptrBox = malloc(sizeof(Box3));

    ptrBox->len = 0;
    ptrBox->name = text;
    ptrBox->ptr = NULL;

    return ptrBox;
}

Box3* createBox3WithOneElement(int value, char* text)
{
    //printf("sizeof(Box3)=%d\n", sizeof(Box3));
    Box3* ptrBox = malloc(sizeof(Box3));



    ptrBox->ptr =  malloc(1 * sizeof(int)); //*(int)
    *(ptrBox->ptr+0) = value;
    ptrBox->ptr[0] = value;
    //int tab[1]
    //tab[0] = value;
    //*(tab+0) = value;

    ptrBox->len = 1;
    ptrBox->name = text;

    return ptrBox;
}

void displayBox3(Box3* byleco){

//    printf("s\n");
    printf("Box %s has: \n", byleco->name );

//    printf("strlen\n");
//    for(int i = 0; i< strlen(byleco->name) ; i++)
//    {
//        printf("%c", *(byleco->name + i) );
//    }
//    printf(" has: \n");
//
//    printf("!=0\n");
//    int i = 0;
//    while( *(byleco->name + i) != '\0')
//    {
//        printf("%c", *(byleco->name + i) );
//        i++;
//    }
//    printf(" has: \n");

    //byleco->len; //<==> (*byleco).len
    for(int i = 0; i< byleco->len; i++)
    {
        printf("%d, ", *(byleco->ptr + i) );
    }
    printf("\n");
    //*(byleco->ptr+0);
    //*(byleco->ptr+1);
    //*(byleco->ptr+2);
}

void AddNewValueToBox3( Box3* b, int value )
{
    int* temp = malloc( (b->len + 1 ) * sizeof(int)  );

    for(int i = 0; i< b->len; i++)
    {
        temp[i] =  b->ptr[i];
    }
    temp[b->len] = value;
    free(b->ptr);
    b->ptr = temp;
    b->len++;
}

void addAtTheEnd(Box3* b, int val){
    //printf("addAtTheEnd.. %s\n", b->name);
    //if( b->len == 0 ) printf("Box %s is Empty!\n", b->name);

    b->len++;
    b->ptr = realloc(b->ptr, (b->len) * sizeof(int) );

    //b->ptr[b->len-1] = val;
    *(b->ptr + b->len-1) = val;
}


int main()
{
    printf("Task3!\n");

    Box3* b0 = createBox3("pudelko nr 0");

    printf("%s\n", b0->name);

    Box3* b1 = createBox3WithOneElement(1, "pudelko nr 1");\
    printf("%s\n", b1->name);


    displayBox3(b0);
    displayBox3(b1);

    AddNewValueToBox3(b0, 1);
    AddNewValueToBox3(b0, 33);
    AddNewValueToBox3(b0, 22);
    AddNewValueToBox3(b0, 4);


    AddNewValueToBox3(b1, 1);
    AddNewValueToBox3(b1, 33);
    AddNewValueToBox3(b1, 22);
    AddNewValueToBox3(b1, 4);
    addAtTheEnd(b1, 8);

    displayBox3(b0);
    displayBox3(b1);

    return 0;
}
