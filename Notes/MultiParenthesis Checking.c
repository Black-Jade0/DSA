#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int Match(struct Stack *s, char bracket)
{
    if (s->top == -1)
    {
        return 0;
    }
    if (s->arr[s->top] == '(' & bracket == ')')
    {
        return 1;
    }
    if (s->arr[s->top] == '[' & bracket == ']')
    {
        return 1;
    }
    if (s->arr[s->top] == '{' & bracket == '}')
    {
        return 1;
    }
    return 0;
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

int peek(struct Stack *ptr, int position)
{
    if (ptr->top - position + 1 < 0 || position <= 0)
    {
        printf("position not awailable\n");
    }
    else
    {
        // printf("%d\n", ptr -> arr[ptr->top - position + 1]);
        return ptr->arr[ptr->top - position + 1];
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct Stack *sp;
    struct Stack s;
    sp = &s;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else if (Match(sp, exp[i]))
            {
                pop(sp);
            }
            else
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        // free(sp);
        free(sp->arr);
        return 1;
    }
    else
    {
        free(sp->arr);
        // free(sp);
        return 0;
    }
}

int main()
{
    // struct Stack *s;
    // s = (struct Stack *)malloc(sizeof(struct Stack));
    // s -> size = 4;
    // s -> top = -1;
    // s -> arr = (char *)malloc(4 * sizeof(char));
    // push(s,'j');
    // push(s,'a');
    // push(s,'i');
    // push(s,'n');

    // // printf("%c\n",s -> arr[0]);

    // printf("%c\n",peek(s,1));
    // printf("%c\n",peek(s,2));
    // printf("%c\n",peek(s,3));
    // printf("%c\n",peek(s,4));

    char exp[] = "[1]((1){(1)})";
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