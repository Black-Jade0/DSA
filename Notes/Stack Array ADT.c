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

struct Stack * push(struct Stack *ptr, int data)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
    return ptr;
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack *ptr, int position){
    if(ptr -> top - position + 1 < 0 || position <= 0){
        printf("position not awailable\n");
    }
    else{
        // printf("%d\n", ptr -> arr[ptr->top - position + 1]);
        return ptr -> arr[ptr->top - position + 1];
    }
    return 0;
}

int main()
{
    // struct Stack s;
    // s.size = 100;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 4;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 11);
    push(s, 23);
    push(s, 99);
    push(s, 75);

    // printf("%d\n",s -> arr[0]);
    // printf("%d\n",s -> arr[1]);
    // printf("%d\n",s -> arr[2]);
    // printf("%d\n",s -> arr[3]);

    printf("%d\n", peek(s,0));
    // printf("%d\n", peek(s,1));
    // printf("%d\n", peek(s,2));
    // printf("%d\n", peek(s,3));
    // printf("%d\n", peek(s,4));
    printf("%d\n", peek(s,5));

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }

    free(s -> arr);
    free(s);

    return 0;
}