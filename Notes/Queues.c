#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int enqueue(struct Queue *q, int val)
{
    if (q->r == q->size - 1)
    {
        printf("Queue is full\n");
        return 0;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        return val;
    }
}

int dequeue(struct Queue *q)
{
    int a;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        // free(q -> arr);
    }
    return a;
}

int main()
{
    struct Queue *q;
    q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 5;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(5 * sizeof(int));

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    // enqueue(q, 5);

    dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);

    enqueue(q, 5);

    printf("%d\n", q->arr[0]);
    printf("%d\n", q->arr[1]);
    printf("%d\n", q->arr[2]);
    printf("%d\n", q->arr[3]);
    printf("%d\n", q->arr[4]);

    return 0;
}