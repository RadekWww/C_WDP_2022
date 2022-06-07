#include <stdio.h>
#include <stdlib.h>




void zapisDoPliku(FILE *fp, char tryb[], char tekst[])
{
    fp = fopen("plik1.txt", tryb); //w+???
    if (fp == NULL) {
        printf("B³¹d otwarcia pliku.");
    return 1;
    }

    fprintf (fp, "%s", "start\n");
    for(int i=0; i<5; i++)
    {
        fprintf (fp, "%d. %s", i, tekst);
        //fprintf (fp, "%s", "\n");
    }
    fclose(fp);
}
//void wywolanieMenuTrybu(char* tryb, int* sterowanieProgramem)
int wywolanieMenuTrybu(char tryb[])
{
    char podajTryb[100];
    printf("To jest program do ...\n");
    printf("Wybierz tryb zapisu do pliku:\n");
    printf("1. nadpisywanie (w)\n");
    printf("2. dopisywanie (a)\n");
    printf("0. Koniec\n");

    scanf("%s", podajTryb);

    if(podajTryb[0] == '1')
    {
         tryb[0] = 'w'; // { 'w', '\0'}
    }
    else if(podajTryb[0] == '2')
    {
         tryb[0] = 'a'; // { 'w', '\0'}
    }
    else if(podajTryb[0] == '0')
    {
        printf("Zakonczono program!\n");
        //*sterowanieProgramem = 0;
        tryb[0] = '0';
        return 0;
    }
    else{
         printf("Brak takiego trybu!\n");
         tryb[0] = '0';
         //continue;
         //break;
         //return 0;
    }

    return 1;
}

int main()
{

    char tekst[] = "Y3 Task1 Hello world!\n";

    printf("%s", tekst);
    FILE *fp;
    int sterowanieProgramem = 1;
    char tryb[] = "0"; // { '0', '\0'}


    while(sterowanieProgramem == 1)
    {
        //wywolanieMenuTrybu(tryb, &sterowanieProgramem);
        sterowanieProgramem = wywolanieMenuTrybu(tryb);

        if(tryb[0] != '0')
        {
            zapisDoPliku(fp, tryb, tekst);
        }

    }

    printf("Koniec programu!\n");
    return 0;
}
