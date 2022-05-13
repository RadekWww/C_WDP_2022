#include <stdio.h>
#include <stdlib.h>


typedef struct node1 {
    int num;
    struct node1 *next;
} Node;


void addOnBeginning(Node** head, int newValue)
{
    Node* newNode = NULL;
    newNode= (Node*) malloc(sizeof(Node));

    newNode->num = newValue;

    newNode->next = *head;
    *head = newNode;
}

void showAllElements(Node* head)
{

    while(head != NULL)
    {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("%\n");
}


void addOnEnd(Node** head, int newValue)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->num = newValue;
    newNode->next = NULL;


    if( (*head) == NULL )
    {
        (*head) = newNode;
        return;
    }

    Node* current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void addRandomValue(Node** head, int from, int thru, int howMany)
{
    //random
    int random = 1;

    for(int i=0; i< howMany; i++)
    {

        addOnEnd(head, random);
    }
}

int main()
{
    printf("Y2_Task3!\n");

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head= (Node*) malloc(sizeof(Node));
    second= (Node*) malloc(sizeof(Node));
    third= (Node*) malloc(sizeof(Node));

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

    second->next = third;
    second->num = 2;

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

    Node* current = (Node*) malloc(sizeof(Node));
    current = head;

       /*
                                   current
                                     |
                                     |
    +---+---+     +---+---+       +----+------+
    | 1  | o----->|  2  | o-----> |  3 | NULL |
    +---+---+     +---+---+       +----+------+
 */
    printf("1st while print\n");
    while(current != NULL)
    {

        printf(" %d ", current->num);
        current = current->next;
    }
    printf("\n");

    printf("2nd while print\n");
    //
    current = head;
    while(current != NULL)
    {

        printf(" %d ", current->num);
        current = current->next;
    }
    printf("\n");


//    //usuwanie drugiego elemnu po nazwie-wskazniu na elemnty
//    head->next = third;
//    free(second);
//
//       /*
//           head
//             |
//             |
//        +---+---+     +----+------+
//        | 1  | o----->|  3 | NULL |
//        +---+---+     +----+------+
//     */
//
//    printf("3th while print\n");
//    //
//    current = head;
//    while(current != NULL)
//    {
//
//        printf(" %d ", current->num);
//        current = current->next;
//    }
//    printf("\n");


    addOnBeginning(&head, 11);
    addOnBeginning(&head, 12);

    current = head;
    while(current != NULL)
    {

        printf(" %d ", current->num);
        current = current->next;
    }
    printf("\n");


    showAllElements(head);
    showAllElements(head);


    addOnEnd(&head, 111);
    addOnEnd(&head, 112);

    showAllElements(head);

    addRandomValue(&head, 0,0, 5);
    showAllElements(head);

    return 0;

}
