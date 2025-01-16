#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct CircularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct CircularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct CircularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Overflow\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct CircularQueue *q)
{
    int a;
    if (isEmpty(q))
    {
        printf("Underflow\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct CircularQueue *q;
    q = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));

    q->size = 4;
    q->f = q->r = 0;
    q->arr = (int *)malloc((q->size) * sizeof(int));

    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);
    // printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q));

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is full\n");
    }

    return 0;
}
