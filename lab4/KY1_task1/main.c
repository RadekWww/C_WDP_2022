#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("KY1_task1!\n");


    FILE *fp;
    char tekst[] = "KY1_task1 Hello world\n";

    char nazwaPliku[] = "nowyPlik2.txt";


    char podajTryb[10];
    char tryb[] = "0";
    int zmiennaSprawdzajaca = 0;


    do {
        printf("Wybierz tryb zapisu do pliku:\n");
        printf("1. nadpisywanie pliku\n");
        printf("2. dopisywanie do pliku\n");
        printf("0. koniec\n");
        //scanf("%s", podajTryb);
        gets(podajTryb);
        printf("%s\n", podajTryb);
        if(podajTryb[0] == '1'){
            tryb[0] = 'w';
            printf("Wybrano tryb 1.\n");
            zmiennaSprawdzajaca = 1;
        }
        else if (podajTryb[0] == '2'){
            tryb[0] = 'a';
            printf("Wybrano tryb 2.\n");
            zmiennaSprawdzajaca = 1;
        }
        else if (podajTryb[0] == '0'){
            printf("Koniec programu.\n");
             return 0;
        }
        else {
            printf("Nieprawidlowa opcja.\n");

        }
    } while (zmiennaSprawdzajaca == 0);



    if ((fp=fopen(nazwaPliku, tryb))==NULL){

        return 1;
    }
    for(int i = 0; i< 10; i++)
    {
        fprintf (fp, "%d %s", i, tekst);
    }

    //fputs(tekst, fp);
    fclose (fp);


    return 0;
}
