#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Y2_Task1\n");

    FILE *fp;

    char tekst[] = "Y2_Task1 Hello world\n";
    char nazwaPliku[] = "plik1.txt";
    char tryb[] = "a";
    char podajTryb[100];
    int sterowanieProgrmem = 1;


    while( sterowanieProgrmem == 1)
    {
        printf("Wybierz tryb zapisu do pliku:\n");
        printf("1. nadpisywanie\n");
        printf("2. dopisywanie\n");
        printf("0. koniec\n");

        //scanf("%s", podajTryb);
        gets(podajTryb);

        if(podajTryb[0] == '1')
        {
            tryb[0] = 'w';
        }
        else if(podajTryb[0] == '2')
        {
            tryb[0] = 'a';
        }
        else if(podajTryb[0] == '0'){
            sterowanieProgrmem = 0;
            tryb[0] = '0';
            printf("koniec dzialania programu");
            //break;
        }
        else{
            tryb[0] = '0';
            printf("bledna opcja");
        }

        if(tryb[0] != '0')
        {
            fp = fopen(nazwaPliku, tryb); //w+???
            if (fp == NULL) {
                printf("B³¹d otwarcia pliku.");
                return 1;
            }
            for(int i=0; i< 5; i++)
            {
                fprintf (fp, "%d. ", i);
                fprintf (fp, "%s", tekst);
            }
            fclose(fp);
            printf("zapisano zmiany do pliku");
            tryb[0] = '0';
        }

    }




    return 0;
}
