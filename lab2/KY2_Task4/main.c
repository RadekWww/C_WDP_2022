#include <stdio.h>
#include <stdlib.h>


typedef struct product
{
    char* name;
    int amount;
    float price;
} Product;

typedef struct box4
{
    Product* arr;
    int currentElements; //try use size_t
    char* name;
} Box4;

int main()
{
    printf("TASK4!\n");

    // to jako fukcja
    Box4* boxA = (Box4*)malloc(sizeof(Box4));
    boxA->arr = NULL;
    boxA->currentElements = 0;
    boxA->name = "Pudelko na produkty";


    //przykald fukcji z tworzeniem odrazu 2 produktow w pude³ku
    //Box4* boxA = (Box4*)malloc(sizeof(Box4));
    boxA->arr = (Product*)malloc(2 * sizeof(Product));
    boxA->currentElements = 2;
    boxA->name = "Pudelko na produkty";


    //dodawanie elementow jako funckja...
    // alokowanie przesterzeni jako miejsce na produkt...
    boxA->arr[0].price = 39;
    boxA->arr[0].amount = 2;
    boxA->arr[0].name = "produkt 1";

    //boxA->arr->price = 39;
    //boxA->arr->amount = 2;
    //boxA->arr->name = "produkt 1";



    return 0;
}
