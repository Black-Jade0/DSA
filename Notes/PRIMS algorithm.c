#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int minimum(int *arr, int n)
{
    int a;
    a = 0;
    int min_val = 1000;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        else if (min_val > arr[i])
        {
            min_val = arr[i];
            a = i;
        }
    }
    return a;
}

int main()
{
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 0, 8, 0, 13, 17, 0},
        {0, 0, 20, 0, 0, 0, 6},
        {8, 20, 0, 11, 0, 0, 0},
        {0, 0, 11, 0, 12, 0, 0},
        {13, 0, 0, 12, 0, 15, 0},
        {17, 0, 0, 0, 15, 0, 18},
        {0, 6, 0, 0, 0, 18, 0}};

    int initial_node;
    initial_node = 4;
    int traverse_node = initial_node;

    int min_index = minimum(a[traverse_node], 7);

    return 0;
}