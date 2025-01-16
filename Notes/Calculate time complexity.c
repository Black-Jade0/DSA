#include <stdio.h>
#include <math.h>

// Your code goes here

/////          https: // www.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-5/

void func(int n)
{
    int sum = 0;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d , %d\n", i, j);
        }
    }
}

// time complexity : n**2

int function(int n)
{
    int i = 0;
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        i = rand() % (n-1);
        printf("this\n");
        return function(i) + function(n - 1 - i);
    }
}

// time complexity : n


struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

int sum(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return sum(node->left) + node->value + sum(node->right);
}

// time complexity : n

int isPrime1(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// time complexity :root(n)
 
int isPrime2(int n)
{
    for (int i = 2; i * i < 10000; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

// time complexity : 

int main(){
    isPrime2(7);
    return 0;
}