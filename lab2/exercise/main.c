#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int t[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d; ", t[i]);
}
void printR1(int t[], int n)
{
    printf("%d; ", t[n-1]);
    if (n != 1) printR1(t, n - 1);
}
void printR2(int t[], int n)
{
    if (n != 1) printR2(t, n - 1);
    printf("%d; ", t[n-1]);
}
void (*wypisz)(int t[], int n); //wskaŸnik na funkcjê

int main()
{
    printf("Hello world!\n");

    char tekst[20];
    printf("Wprowadz napis: ");
    gets(tekst);
//    for (int i = 0; tekst[i]; ++i) {
//        printf("%c", tekst[i]);
//    }
    //printf("\n");
    printf(tekst); //mo¿na równie¿ tak
    printf("\n");
    //printf("%s", tekst); //i tak
    //printf("\n");
    //printf("%s", &tekst[0]);//lub tak
    //printf("\n");


    char *tekst2;
    tekst2 = (char*)malloc(20*sizeof(char));
    printf("Wprowadz napis: ");
    gets(tekst2);
    printf(tekst2); //mo¿na równie¿ tak
    printf("\n");

    char *tekst3;
    tekst3 = (char*)malloc(20*sizeof(char));
    tekst3 = "adf\0";
    printf(tekst3);
    printf("\n");

    char *tekst01 = strcat(tekst, tekst2);
    printf(tekst01);
    free(tekst01);

    int a= 1;


    int tab [10] = {1,2,4,8,16,32,64,128,256,512};
    //--------------------------
    wypisz = printR1; //nazwa funkcji to jej adres
    wypisz(tab,10);
    wypisz = print;
    wypisz(tab,10);


    return 0;
}
