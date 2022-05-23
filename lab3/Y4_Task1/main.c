#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int num;
    struct node* next;
} Node;


Node* addHeadWithReturn( Node* head, int newValue )
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->num = newValue;
    newNode->next = NULL;

    if(head == NULL)
    {
        return newNode;
    }

    newNode->next = head;
    return newNode;

}

void addHead( Node** ptrToHead, int newValue )
{

    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->num = newValue;

    newNode->next = *ptrToHead;

    *ptrToHead = newNode;

}

void display( Node* head )
{
    if(head == NULL)
    {
        printf("lista jest pusta");
        return;
    }

    Node* current = head;
    while( current != NULL)
    {
        printf("%d ", current->num);

        current = current->next;

    }
    printf( "\n");

}



Node*  addToEndWithReturn(Node* head, int newValue)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->num = newValue;
    newNode->next = NULL;

    if(head == NULL)
    {
        return newNode;
    }

    Node* current = head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;

    return head;

}

void addToEnd(Node** head, int newValue)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->num = newValue;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head =  newNode;
    }

    Node* current = *head;

    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}


void addRandom(Node** ptrToHead, int howMany)
{
    int random = 23;

    for(int i = 0; i< howMany; i++ )
    {
        addToEnd(ptrToHead, random);
    }

}


int main()
{
    printf("Y4_task1!\n");

    Node* head = (Node*) malloc(sizeof(Node)) ;
    Node* second = (Node*) malloc(sizeof(Node)) ;
    Node* third = (Node*) malloc(sizeof(Node)) ;

 /*
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    */


    head->num = 1;
    head->next = NULL;

     /*
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | 1 |NULL |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    */

    head->next = second;

        /*
       head          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 1  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+
  */

    second->num = 2;
    second->next = third;
    //head->next->num = 2;
    //head->next->next = third;

         /*
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+
*/
    third->num = 3;
    third->next = NULL;

         /*
       head
         |
         |
    +---+---+     +---+---+       +----+------+
    | 1  | o----->|  2  | o-----> |  3 | NULL |
    +---+---+     +---+---+       +----+------+
 */
    //Node* current = malloc(sizeof(Node));
    Node* current = head;

    printf("1st while v A:\n");
    while(current->next != NULL)
    {
        printf( " %d ", current->num );

        current = current->next;
    }
    printf( " %d ", current->num );
    printf( "\n");


    printf("1st while v B:\n");
    current = head;
    while(current != NULL)
    {
        printf( " %d ", current->num );

        current = current->next;
    }
    printf( "\n");


     /*
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+
*/

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

    printf("2nd while v B:\n");
    current = head;
    int counter = 0;
    while(current != NULL)
    {
        printf( " %d ", current->num );

        current = current->next;

        counter ++;
    }
    printf( "counter: %d\n", counter);
    printf( "\n");


    head = addHeadWithReturn(head, 25);

    addHead(&head, 26);


    printf("3th while v B:\n");
    current = head;
    counter = 0;
    while(current != NULL)
    {
        printf( " %d ", current->num );

        current = current->next;

        counter ++;
    }
    printf( "counter: %d\n", counter);
    printf( "\n");


    addHead(&head, 2);
    addHead(&head, 1);
    display(head);


    head = addToEndWithReturn(head, 101);
    head = addToEndWithReturn(head, 102);
    display(head);

    Node* head2 = NULL;

    head2 = addToEndWithReturn(head2, 11);
    head2 = addToEndWithReturn(head2, 12);
    display(head2);

    addToEnd(&head2, 13);
    addToEnd(&head2, 14);
    display(head2);

    addRandom(&head2, 5);
    display(head2);



    return 0;
}
