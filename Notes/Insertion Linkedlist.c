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

// Inserting at first place, time complexity = O(1)

struct Node *InsertAtFirst(struct Node **head_add, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = *head_add;
    *head_add = ptr;
    return ptr;
}

//    //    OR : withouth taking a pointer to the head, u would need to update the value of head manually like:
//    //    head = InsertAtFirst(head, 1);

// struct Node *InsertAtFirst(struct Node *head, int data)
// {
//     struct Node *ptr;
//     ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;
//     ptr->next = head;
//     head = ptr;
//     return head;
// }

// Inserting in between, time complexity = O(n)

struct Node *InsertInBet(struct Node **head_add, int data, int index)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr -> data = data;

    if(index ==0){
        ptr->next = *head_add;
        *head_add = ptr;
        return ptr;
    }

    struct Node *p;
    p = *head_add;
    int i = 0;
    
    while (i != index-1)
    {
        p = p ->next;
        i++;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    // return ptr;
}

// Inserting at end, time complexity = O(n)

struct Node *InsertAtEnd(struct Node **head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p;
    p = *head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return *head;
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

    linkedlistTraversal(head);
    printf("\n");

    InsertAtFirst(&head, 0);
    linkedlistTraversal(head);
    printf("\n");

    // InsertInBet(&head,100,0);
    // linkedlistTraversal(head);
    // printf("\n");

    // InsertAtEnd(&head,1000);
    // linkedlistTraversal(head);
    // printf("\n");
    
    return 0;
}