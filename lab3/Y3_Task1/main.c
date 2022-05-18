#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int num;
    struct node *next;
} Node;


void addOnStart( Node** head, int newValue )
{
    Node* newNode = malloc(sizeof(Node));
    newNode->num = newValue;

    newNode->next = *head;

    *head = newNode;

}

void display( Node* head )
{
    if( head == NULL){
        printf("lista jest pusta!\n");
        return;
    }

    Node* current = malloc(sizeof(Node));
    current = head;

    while(current != NULL){

        printf( "%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

void addOnEnd( Node** ptrToHead, int newValue )
{
//    if(head == NULL)
//    {
//        addOnStart(head, newValue);
//        return;
//    }
    Node* newNode = malloc(sizeof(Node));
    newNode->num = newValue;
    newNode->next = NULL;

    if( (*ptrToHead) == NULL)
    {
        (*ptrToHead) = newNode;
        return;
    }


    Node* current = malloc(sizeof(Node));
    current = (*ptrToHead);

    while(current->next != NULL ){
        current = current->next;
    }
    current->next = newNode;




}



void addRandom(Node** ptrToHead, int howMany)
{
    int random = 23;

    for(int i = 0; i< howMany; i++ )
    {
        addOnEnd(ptrToHead, random);
    }

}


int main()
{
    printf("Lab3_Y3_task1!\n");

    //struct node *head2 = NULL;
    Node* head = NULL;

    head = malloc(sizeof(Node));

    Node* second = malloc(sizeof(Node));
    Node* third = malloc(sizeof(Node));

  /*
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    */

    head->num =1;
    head->next = second;

    /*
       head          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 1  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+
  */
    second->num =2;
    second->next = third;
    //head->next->next = third;

     /*
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+
*/

    third->num =3;
    third->next = NULL;


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

    printf("1st while:");
    while(current != NULL){
        printf(" %d ", current->num );
        current = current->next;
    }
    printf("\n");


    printf("2nd while:");
    current = head;
    while(current != NULL){
        printf(" %d ", current->num );
        current = current->next;
    }
    printf("\n");


        /*
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+
*/

    head->next = second->next;
    //head->next = third;
    free(second);

            /*
//           head
//             |
//             |
//        +---+---+     +----+------+
//        | 1  | o----->|  3 | NULL |
//        +---+---+     +----+------+
//     */

    printf("3th while:");
    current = head;
    int size = 0;
    while(current != NULL){
        printf(" %d ", current->num );
        size++;
        current = current->next;
    }
    printf("size=%d\n", size);
    printf("\n");


    addOnStart(&head, 25);
    addOnStart(&head, 28);

//    printf("4th while aftre adds:");
//    current = head;
//    size = 0;
//    while(current != NULL){
//        printf(" %d ", current->num );
//        size++;
//        current = current->next;
//    }
//    printf("size=%d\n", size);
//    printf("\n");

    display(head);

    addOnEnd(&head, 100);
    addOnEnd(&head, 101);

    display(head);

    addRandom(&head, 5);
    display(head);

    return 0;
}
