#include <stdio.h>
#include <stdlib.h>



void printStrings(char* str)
{
    printf("%s\n", str);

    int len = strlen(str);
    for(int i=0; i< len; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    int j=0;
    while (str[j] != '\0')
    {
        printf("%c", str[j]);
        j++;
    }
    printf("\n");


}

int main()
{
    printf("T5-6!\n");


    char s1[5] = { 't', 'e', 's', 't', '\0' };
    //brak znaku konca stringa \0
    char s2[4] = { 'a', 'u', 't', 'o' };

    char s3[] = "test nr2";

    printStrings(s1);

    //wyswietlanie wiekszej liczby znakow, bo string s2 nie posiada znaku konca lini..
    printStrings(s2);
    printStrings(s3);

    char s4[50];

    gets(s4); //scanf("%s",s4);
    printStrings(s4);




    return 0;
}
