#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("KY2_T1\n");

    char tekst[] = "KY2_T1 Hello world\n";
    char podajTryb[100];
    char tryb[] = "0";
    int zywotnoscProgramu = 0;


    while(zywotnoscProgramu == 0)
    {


        printf("Wybierz tryb zapisu do pliku:\n");
        printf("1. nadpisywanie\n");
        printf("2. dopisywanie\n");
        printf("0. koniec\n");


        //scanf("%s", podajTryb);
        gets(podajTryb);
        printf("Wybrano: %s\n", podajTryb);

        if(podajTryb[0] == '1')
        {
            tryb[0] = 'w';
        }
        else if(podajTryb[0] == '2')
        {
            tryb[0] = 'a';
        }
        else if(podajTryb[0] == '0')
        {
            zywotnoscProgramu =1;
            tryb[0] = '0';
            //break;
        }


        if(tryb[0] != '0')
        {
            FILE *fp;
            fp = fopen("plik1.txt", tryb); //w+???
            if (fp == NULL) {
                printf("B³¹d otwarcia pliku.");
                return 1;
            }

            fprintf (fp, "%s", tekst);
            for (int i=0; i< 5; i++)
            {
                fprintf (fp, "%d ", i);
                fprintf (fp, "%s", tekst);
            }

            fclose(fp);
            tryb[0] = '0';
        }
        else{
            printf("Bledny tryb\n");
        }
    }

    return 0;
}
