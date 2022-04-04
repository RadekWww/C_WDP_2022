#include <stdio.h>
#include <stdlib.h>


void printInfoVer1(int value, int* ptrValue){
    printf("Wartosc zmiennej:%d\n", value);
    printf("Adres zmiennej:%d\n", &value);
    printf("Wskaznik - Adres na ktory wskazuje wskaznik:%d\n", ptrValue);
    printf("Wartosc wskazywana przez wskaznik - wartosc pod adresem: %d\n\n", *ptrValue);
}


int main()
{
    //za pomoc¹ debugera mozna pokazaæ
    printf("WSKAZNIKI!\n");

    int a = 1;
    int b;
    int* ptr;
    int* ptr3 = NULL;
    void* ptrVoid;
    ptr = &a;
    int* ptr2=&b;
    ptrVoid = &b;
    b = 112;



    printf("PRINTF before!\n");
    printf("Wartosc zmiennej:%d\n", a);
    printf("Adres zmiennej:%d\n", &a);
    printf("Wskaznik1 - Adres na ktory wskazuje wskaznik:%d\n", ptr);
    printf("Wartosc wskazywana przez wskaznik1 - wartosc pod adresem: %d\n", *ptr);
    printf("Adres wskaznika1: %d\n", &ptr);
    printf("Wskaznik2 - Adres na ktory wskazuje wskaznik:%d\n", ptr2);
    printf("Wartosc wskazywana przez wskaznik2 - wartosc pod adresem: %d\n", *ptr2);
    printf("Adres wskaznika2: %d\n", &ptr2);
    printf("\n");

    a+=2;
    printf("PRINTF after +2!\n");
    printf("Wartosc zmiennej:%d\n", a);
    printf("Adres zmiennej:%d\n", &a);
    printf("Wskaznik1 - Adres na ktory wskazuje wskaznik:%d\n", ptr);
    printf("Wartosc wskazywana przez wskaznik1 - wartosc pod adresem: %d\n", *ptr);
    printf("Wskaznik2 - Adres na ktory wskazuje wskaznik:%d\n", ptr2);
    printf("Wartosc wskazywana przez wskaznik2 - wartosc pod adresem: %d\n\n", *ptr2);;

    *ptr+=1;
    printf("PRINTF after +1!\n");
    printf("Wartosc zmiennej:%d\n", a);
    printf("Adres zmiennej:%d\n", &a);
    printf("Wskaznik1 - Adres na ktory wskazuje wskaznik:%d\n", ptr);
    printf("Wartosc wskazywana przez wskaznik1 - wartosc pod adresem: %d\n", *ptr);
    printf("Wskaznik2 - Adres na ktory wskazuje wskaznik:%d\n", ptr2);
    printf("Wartosc wskazywana przez wskaznik2 - wartosc pod adresem: %d\n\n", *ptr2);

    printf("PRINTF func call\n");
    printInfoVer1(a, ptr);



    *ptr+=10;
    printf("PRINTF after +10!\n");
    printf("Wartosc zmiennej:%d\n", a);
    printf("Adres zmiennej:%d\n", &a);
    printf("Wskaznik1 - Adres na ktory wskazuje wskaznik:%d\n", ptr);
    printf("Wartosc wskazywana przez wskaznik1 - wartosc pod adresem: %d\n", *ptr);
    printf("Wskaznik2 - Adres na ktory wskazuje wskaznik:%d\n", ptr2);
    printf("Wartosc wskazywana przez wskaznik2 - wartosc pod adresem: %d\n\n", *ptr2);

    //zwiêkszenie wartosci pod adresem
    (*ptr2)++;
    (*(int*)ptrVoid)++;

    //zwiêkszenie wartosci pod adresem
    ++*ptr2;

    //zwiêkszenie adresu
    *ptr2++;
    *ptrVoid++;

    return 0;
}
