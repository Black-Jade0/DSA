#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void EnQueue(int val)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Queue is Full");
        return;
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (f == NULL)
        {
            f = r = ptr;
            return;
        }
        else
        {
            r -> next = ptr;
            r = ptr;
            return;
        }
    }
}

int DeQueue()
{
    int a;
    if (r == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        struct Node *ptr;
        ptr = f;
        f = f->next;
        a = ptr->data;
        free(ptr);
    }
    return a;
}

int main()
{
    // struct Node * head;
    // struct Node * second ;
    // struct Node * third ;
    // struct Node * fourth ;

    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // fourth = NULL;

    // head -> next = second;
    // second -> next = third;
    // third -> next = fourth;

    linkedListTraversal(f);

    EnQueue(45);
    EnQueue(55);
    EnQueue(35);
    EnQueue(25);
    EnQueue(65);
    EnQueue(15);
    DeQueue();
    linkedListTraversal(f);

    return 0;
}