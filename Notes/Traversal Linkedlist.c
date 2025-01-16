#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr -> data);
        ptr = ptr->next;
    }
}

int main()
{
    // struct Node *head;
    // head = malloc(sizeof(struct Node));
    // head -> data = 100;
    // head -> next = (struct Node *)malloc(sizeof(struct Node));

    // head -> next -> data = 10;
    // head -> next -> next = NULL;

    // printf("%d\n", head -> data);
    // printf("%d\n",((*head).next) -> data);

    ////       IF U DONT WANT TO HAVE THE HEAD AS A POINTER, JUST START WITH A NODE ITSELF :

    // struct Node head;

    // head.next = malloc(sizeof(struct Node));
    // head.data = 100;

    // (head.next)->data = 10;
    // (head.next)->next = NULL;

    // printf("%d \n", head.data);
    // printf("%d\n", (head.next)->data);

    struct Node *head ;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head -> next = second;
    second -> next =third;
    third -> next = NULL;

    head -> data = 1;
    second -> data = 2;
    third -> data = 3;

    linkedlistTraversal(head);

    return 0;
}