#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int num;
    struct node *next;
} Node;


void addOnStart(Node** head, int newValue){

    Node* newNode = malloc(sizeof(Node));

    //Node* temp = malloc(sizeof(Node));
    //temp = *head
    newNode->next = *head;
    *head =  newNode;

    newNode->num = newValue;
}

void addRandom(Node** head, int howMany)
{
    int random = 23;

    for(int i = 0; i< howMany; i++ )
    {

        addOnStart(head, random);
    }

}

void printListFromHead(Node* head)
{
    Node* current = malloc(sizeof(Node));
    current = head;
    while(current != NULL)
    {
        printf( "%d ", current->num );
        current = current->next;
    }
    printf( "\n" );
    free(current);

}

void append(Node** head, int newValue){


    if( (*head) == NULL)
    {
         Node* newNode = malloc(sizeof(Node));
         newNode->num = newValue;
         newNode->next = NULL;
         (*head) =newNode;
         return;
    }


    //Node* current = malloc(sizeof(Node));
    Node* current = *head;

    while(1)
    {
        if(current->next == NULL)
        {
            break;
        }
        current=current->next;
    }

//    while(current->next != NULL)
//    {
//        current = current->next;
//    }

    Node* newNode = malloc(sizeof(Node));
    newNode->num = newValue;
    newNode->next = NULL;

    current->next = newNode;

}



int main()
{
    printf("KY2_task1!\n");

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = (Node*) malloc(sizeof(Node));
    second = (Node*) malloc(sizeof(Node));
    third =  malloc(sizeof(Node));

  /*
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    */

    head->next = second;
    head->num = 1;

/*
       head          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 1  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+
  */

    //second->next = third;
    head->next->next = third;
    second->num = 22;

     /*
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+
*/
    third->next = NULL;
    third->num = 3;

       /*
       head
         |
         |
    +---+---+     +---+---+       +----+------+
    | 1  | o----->|  2  | o-----> |  3 | NULL |
    +---+---+     +---+---+       +----+------+
 */
    Node* current = malloc(sizeof(Node));
    current = head;

    printf("1st while\n");
    while(current != NULL){
        printf( " %d ", current->num);
        current = current->next;
    }
    printf("\n");

    printf("2nd while\n");
    current = head;
    while(current != NULL){
        printf( " %d ", current->num);
        current = current->next;
    }
    printf("\n");

    //usuwanie drugiego elemnu po nazwie-wskazniu na elemnty
    head->next = third;
    free(second);

        /*
//           head
//             |
//             |
//        +---+---+     +----+------+
//        | 1  | o----->|  3 | NULL |
//        +---+---+     +----+------+
//     */

    printf("3th while after delete\n");
    current = head;
    while(current != NULL){
        printf( " %d ", current->num);
        current = current->next;
    }
    printf("\n");


    addOnStart(&head, 25);
    addOnStart(&head, 11);

    printf("4th while after add\n");
    current = head;
    while(current != NULL){
        printf( " %d ", current->num);
        current = current->next;
    }
    printf("\n");

    addOnStart(&head, 2);
    addOnStart(&head, 1);
    printListFromHead(head);




    append(&head, 333);
    append(&head, 334);
    printListFromHead(head);


    Node* head2 = NULL;

    append(&head2, 1333);
    append(&head2, 1334);
    append(&head2, 1335);
    printListFromHead(head2);

    addRandom(&head2, 5);
    printListFromHead(head2);

    return 0;
}
