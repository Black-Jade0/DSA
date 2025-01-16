#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
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

void push(struct Stack *s, char val)
{
    if (isFull(s))
    {
        printf("Stack overflow!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int parenthesisMatch(const char *exp)
{
    // Create and initialize the stack
    struct Stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp))
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
    // struct Stack *s;
    // s = (struct Stack *)malloc(sizeof(struct Stack));
    // s->size = 100;
    // s->top = -1;
    // s->arr = (char *)malloc(s->size * sizeof(char *));
    // push(s, '(');
    // if(isEmpty(s)){
    //     printf("it is empty\n");
    // }
    // else
    // {
    //     printf("it is not empty\n");
    // }
    
    // pop(s);

    // if (isEmpty(s))
    // {
    //     printf("it is empty\n");
    // }
    // else
    // {
    //     printf("it is not empty\n");
    // }

    const char *exp = "((8)(*--$$9))";
    // Check if stack is empty
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    
    return 0;
}