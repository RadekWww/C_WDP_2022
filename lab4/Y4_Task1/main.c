#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Y4_Task1!\n");

    char tekst[] = "Hello world Y4_Task1\n";
    char tekst2[] = "TEST";

    char podajTryb[100];
    char tryb[] = "0";   /// { '0', '\0' }

    int sterowanieProgramem = 1;

    FILE *fp;

    //printf( "rozmiar = %d\n", strlen(tryb)) ;
    //printf( "tryb[] = '%c'='%d' '%c'='%d'\n", tryb[0], tryb[0], tryb[1], tryb[1]) ;

    //while(sterowanieProgramem == 1)
    while(1)
    {
        printf("Wybierz tryb zapisu do pliku:\n");
        printf("1. nadpisywanie\n");
        printf("2. dopisywanie\n");
        printf("0. koniec\n");

        //scanf("%s", podajTryb);
        gets(podajTryb);

        if(podajTryb[0] == '1')
        {
            printf("wybrano 1. nadpisywanie\n");
            tryb[0] = 'w';
        }
        else if(podajTryb[0] == '2')
        {
            printf("wybrano 2. dopisywanie\n");
            tryb[0] = 'a';
        }
        else if(podajTryb[0] == '0'){
            printf("Wybrano 0 Koniec\n");
            tryb[0] = '0';
            // sterowanieProgramem = 0;
            break; // return 0;

        }
        else{
            printf("Brak takie opcji\n");
            tryb[0] = '0';
            continue;
        }

        if( tryb[0] != '0')
        {

            fp = fopen("plik1.txt", tryb); //w+???
            if (fp == NULL) {
                printf("B³šd otwarcia pliku.");
                return 1;
            }
            for(int i=0; i< 5; i++)
            {
                fprintf (fp, "%d. ", i);
                fprintf (fp, "%s", tekst);
            }
            fclose(fp);
            printf("zapisano zmiany do pliku");
        }

        ///po ang
        //wyswietlMenu();
        //... pobierzTryb(...);
        //... zapisDoPliku(...);

    }




    return 0;
}
