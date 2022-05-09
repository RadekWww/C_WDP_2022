#include <stdio.h>
#include <stdlib.h>

typedef struct node1 {
    int num;
    struct node1 *ptr;
} Node;


void addOnStart(Node** head, int value ){

    Node* newElement = NULL;
    newElement = (Node*) malloc(sizeof(Node));

    Node* tempHead = (*head);
    newElement->ptr =tempHead;
    newElement->num = value;

    *head = newElement;
}

void show(Node* head)
{

    if(head== NULL){

        printf("List is empty");
    }
    else{
        printf("[");
        Node* current = head;
        do{
            printf("%i->", current->num);

            current = current->ptr;
        } while(current != NULL);
        printf("NULL]\n");
    }

}


void addToTail(Node** head, int newValue)
{
    Node* newElement = (Node*) malloc(sizeof(Node));
    newElement->num = newValue;
    newElement->ptr = NULL;
    Node* current = *head;

    if((*head) == NULL)
    {
        (*head) = newElement;
    }
    else{

        while(current->ptr != NULL)
        {
            current = current->ptr;
        }
        current->ptr = newElement;
    }
}

void append(Node** head_ref, int new_data)
{
    Node* new_node = ( Node*) malloc(sizeof( Node));
    Node *last = *head_ref;

    new_node->num  = new_data;
    new_node->ptr = NULL;

    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->ptr != NULL)
        last = last->ptr;
    last->ptr = new_node;
    return;
}

int main()
{
    printf("Task1!\n");


    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head =  (Node*) malloc(sizeof(Node));
    second =  (Node*) malloc(sizeof(Node));
    third =  (Node*) malloc(sizeof(Node));

     /*
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    */

    head->num = 1;
    head->ptr = second;

    /*
       head          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 1  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+
  */

    second->ptr = third;
    second->num = 2;

 /*
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+
*/

    third->ptr = NULL;
    third->num = 3;

    /*
           head
             |
             |
        +---+---+     +---+---+       +----+------+
        | 1  | o----->|  2  | o-----> |  3 | NULL |
        +---+---+     +---+---+       +----+------+
     */


     Node* current =  (Node*) malloc(sizeof(Node));
     current = head;
     while(current != NULL)
     {
         printf(" %d ", current->num);
         current = current->ptr;

     }
     printf("\n");

     head->ptr = third;
     free(second);

     /*
           head
             |
             |
        +---+---+     +----+------+
        | 1  | o----->|  3 | NULL |
        +---+---+     +----+------+
     */


     current = head;
     while(current != NULL)
     {
         printf(" %d ", current->num);
         current = current->ptr;

     }
     printf("\n");

     addOnStart(&head, 25);
     addOnStart(&head, 8);

     current = head;
     while(current != NULL)
     {
         printf(" %d ", current->num);
         current = current->ptr;

     }
     printf("\n");

     show(head);

     append(&head,11);

     addToTail(&head, 1);
     addToTail(&head, 2);
     show(head);

    return 0;
}
