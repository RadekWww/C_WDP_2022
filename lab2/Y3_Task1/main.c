#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 100

void AddValueToBox1(int* tab, int* currentElements,  int value ) //int tab[]
{
    if(*currentElements < SIZE_MAX)
    {
        //tab[*currentElements] = value;
        *(tab + *currentElements) = value;
        (*currentElements)++;
    }
}

void display(int* tab, int currentElements)
{
    if(currentElements <=0 ) printf("Box is Empty!\n");
    else
    {
        for(int i=0; i<currentElements; i++)
        {
            //printf("%d, ", tab[i]);
            printf("%d, ", *(tab + i) );
        }
        printf("%\n");
    }


}

void deleteAll(int* tab, int* currentElements )
{
    for(int i=0; i < *currentElements; i++)
    {
        *(tab + i) = 0;
    }
    *currentElements = 0;
}

int findAndPrintMaxElement(int* tab, int currentElements)
{
    int max =  *tab+0; //tab[0];

    for(int i=1; i < currentElements; i++)
    {

        if(max < *(tab+i) )
        {
            max = *(tab + i);
        }

    }
    printf("max = %d\n", max);
    return max;
}

void deleteValue (int * tab, int * currentElements, int val)
{

    int indexToDelete = 0;
    for(int i=0; i < *currentElements; i++)
    {
        if( tab[i] == val)
        {
            indexToDelete = i;
        }
    }
    for(int i=indexToDelete; i < *currentElements; i++)
    {
        tab[i] = tab[i+1];
    }
    tab[*currentElements] = 0;

    (*currentElements)--;

}



int main()
{
    printf("Task1!\n");

    int arr[SIZE_MAX] = { 0 };
    int currentElements = 0; //try use size_t


    arr[currentElements] = 1;
    currentElements++;
    arr[currentElements] = 22;
    currentElements++;
    arr[currentElements] = 4;
    currentElements++;

    AddValueToBox1(arr, &currentElements, 44);

    display(arr, currentElements);

    deleteAll(arr, &currentElements);
    deleteAll(&arr[0], &currentElements);

    display(arr, currentElements);

    AddValueToBox1(arr, &currentElements, 1);
    AddValueToBox1(arr, &currentElements, 3);
    AddValueToBox1(arr, &currentElements, 33);
    AddValueToBox1(arr, &currentElements, 2);
    display(arr, currentElements);

    findAndPrintMaxElement(arr, currentElements);


    deleteValue(arr, &currentElements, 1);
    display(arr, currentElements);
    deleteValue(arr, &currentElements, 2);
    display(arr, currentElements);
    deleteValue(arr, &currentElements, 3);
    display(arr, currentElements);
    deleteValue(arr, &currentElements, 33);
    display(arr, currentElements);

    return 0;
}
