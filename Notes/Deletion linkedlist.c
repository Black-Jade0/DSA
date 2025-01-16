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
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *DeleteFirst(struct Node **head_add)
{
    struct Node *ptr;
    ptr = *head_add;
    *head_add = (ptr)->next;
    free(ptr);
    return *head_add;
}

struct Node *DeleteAtIndex(struct Node **head_add, int index)
{

    struct Node *ptr;
    ptr = *head_add;

    struct Node *ptr1;
    ptr1 = (*head_add)->next;
    int i = 0;

    while (i < index - 1)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
        i++;
    }

    ptr->next = ptr1->next;
    free(ptr1);
    return *head_add;
}

struct Node *DeleteLast(struct Node **head_add)
{
    struct Node *ptr;
    ptr = *head_add;

    struct Node *ptr1;
    ptr1 = (*head_add)->next;

    while (ptr1 -> next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }

    ptr->next = NULL;
    free(ptr1);
    return *head_add;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    // DeleteFirst(&head);
    // DeleteFirst(&head);
    // DeleteAtIndex(&head, 2);
    DeleteLast(&head);
    linkedlistTraversal(head);
    return 0;
}