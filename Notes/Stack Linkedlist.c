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

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    printf("Its never full!\n");
    return 0;
}

//    //    Inserting at last everytime, putting in from side 1; ----> BIG NO

struct Node *push1(struct Node **top_add, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (*top_add == NULL)
    {
        *top_add = ptr;
        (*top_add)->next = NULL;
        return *top_add;
    }

    else
    {
        struct Node *p;
        p = *top_add;

        while (p -> next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
        return *top_add;
    }
}

//    //    Inserting at first everytime, putting in from side 2;

void push2(struct Node **top, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = (*top);
    *top = ptr;
}

int pop(struct Node **top_add)
{
    if (isEmpty(*top_add))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        struct Node *n = *top_add;
        *top_add = (*top_add)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node *top,int position)
{
    struct Node * ptr = top;
    int i = 1;
    while (i < position)
    {
        ptr = ptr -> next;
        i++;
    }
    printf("%d\n",ptr -> data);
    return ptr -> data;
     
}

int main()
{
    struct Node *top;
    top = NULL;
    push2(&top,0);
    push2(&top,1);
    push2(&top,2);
    push2(&top,3);

    // pop(&top);
    // pop(&top);
    // pop(&top);

    peek(top,1);
    peek(top,2);
    peek(top,3);
    peek(top,4);

    // push1(&top, 0);
    // push1(&top, 1);
    // push1(&top, 2);
    // push1(&top, 3);

    // linkedlistTraversal(top);
    return 0;
}