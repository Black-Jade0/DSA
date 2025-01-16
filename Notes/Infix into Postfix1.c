#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

char stacktop(struct Stack *sp)
{
    return sp->arr[sp->top];
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

struct Stack *push(struct Stack *ptr, int data)
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

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int operator_check(char op)
{
    if (op == '-' || op == '+' || op == '*' || op == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int OperatorPreference(char opp)
{
    if (opp == '/' || opp == '*')
    {
        return 3;
    }
    else if (opp == '+' || opp == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *ConvertIntoPostfix(char *str)
{
    char *postfix;
    postfix = (char *)malloc((strlen(str) + 1) * sizeof(char));

    struct Stack *sp;
    struct Stack s;
    sp = &s;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    postfix[0] = '\0';

    for (int i = 0; str[i] != '\0';)
    {
        char bracket[] = {str[i], '\0'};
        if (operator_check(str[i]))
        {
            if (OperatorPreference(str[i]) > OperatorPreference(stacktop(sp)))
            {
                push(sp, str[i]);
                i++;
            }
            else
            {
                char popped[] = {pop(sp), '\0'};
                strcat(postfix, popped);
            }
        }
        else
        {
            strcat(postfix, bracket);
            i++;
        }
    }

    while (!isEmpty(sp))
    {
        char popped[] = {pop(sp), '\0'};
        strcat(postfix, popped);
    }

    strcat(postfix,"\0");
    // postfix[strlen(postfix)] = '\0';
    printf("%s\n", postfix);
    return postfix;
}

int main()
{

    char *arr;
    arr = (char *)malloc(10 * sizeof(char));
    strcpy(arr, "x+y/z-k*a");

    // char arr[] = "x+y/z-k*a";

    // char arr[] = {'x','+','/','z','-','k','*','a','\0'};

    ConvertIntoPostfix(arr);

    return 0;
}