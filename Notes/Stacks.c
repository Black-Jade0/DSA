#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct Stack s;
    // s.size = 100;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    if (isEmpty(s))
    {
        printf("it is empty\n");
    }
    else
    {
        printf("it is full\n");
    }

    printf("%d\n", s->arr);

    s->arr[0] = 7;
    s->top++;

    printf("%d\n", s->arr);
    printf("%d\n", s->arr[0]);

    if (isFull(s))
    {
        printf("it is full\n");
    }
    else
    {
        printf("it is empty\n");
    }

    return 0;
}