#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedlistTraversal1(struct Node *head) {
    struct Node * ptr;
    ptr = head;
    while (ptr -> next != head ) {
        printf("%d \n", ptr -> data);
        ptr = ptr->next;
    }
    printf("%d\n",ptr -> data);
}

void linkedlistTraversal2(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void InsertFirst(struct Node **head_add, int data){
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p;
    p = *head_add;
    do
    {
        p = p -> next;
    } while (p -> next != *head_add);
    
    p->next = ptr;
    ptr -> next = *head_add;
    *head_add = ptr;
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
    fourth->next = head;

    linkedlistTraversal1(head);

    InsertFirst(&head, 0);
    linkedlistTraversal1(head);

    return 0;
}