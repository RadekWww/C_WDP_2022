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
    Product* ptr;
    int len; //try use size_t
    char* name;
} Box4;

#include <string.h>

void checkString(char* str){


    printf("%s\n", str);

    int len = strlen(str);
    for(int i=0; i<len; i++){

         printf("%c", str[i]);
    }
    printf("\n");


    int i = 0;
    while(str[i] != '\0'){
         printf("%c", str[i]);
         i++;
    }
    printf("\n");

}

int main()
{
    printf("TASK4-5\n");

    Box4* b0 ;

    //b0->ptr->amount;

    checkString("test nr1");

    char s1[5] = { 't', 'e', 's', 't', '\0' };
    checkString(s1);
    //brak znaku konca stringa \0
    char s2[4] = { 'a', 'u', 't', 'o' };
    checkString(s2);

    char s3[] = "test nr2";
    checkString(s3);

    return 0;
}
