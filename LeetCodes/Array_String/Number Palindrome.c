#include <stdio.h>
#include <stdlib.h>

int len(int x)
{
    int a = 0;
    if (x == 0)
    {
        return 0;
    }
    while (x != 0)
    {
        x = x / 10;
        a++;
    }
    return a;
}

int isPalindrome(int num)
{
    int x = num;
    if (x < 0)
    {
        return 0;
    }
    int length = len(x);
    struct Stack
    {
        int arr[100];
        int h;
    };
    int i = 1;
    struct Stack cont;
    cont.h = 0;
    while (i < (length / 2) + 1)
    {
        int a = x - ((x / 10) * 10);
        x = x / 10;
        cont.arr[cont.h] = a;
        cont.h++;
        i++;
    }
    if (length % 2 != 0)
    {
        x = x / 10;
    }
    while (i > 1)
    {
        int a = x - ((x / 10) * 10);
        x = x / 10;
        cont.h--;
        if (a != cont.arr[cont.h])
        {
            return 0;
        }
        i--;
    }
    if (cont.h == 0)
    {
        return 1;
    }
    
    return 1;
}

int main()
{
    int num = 23454321;
    if (isPalindrome(num))
    {
        printf("a plaindrome\n");
    }
    else
    {
        printf("not a palindrome\n");
    }
    return 0;
}