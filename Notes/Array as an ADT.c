#include <stdio.h>
#include <stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myarray *a, int t_size, int u_size)
{
    (*a).total_size = t_size;
    (*a).used_size = u_size;
    (*a).ptr = (int *)malloc(t_size * sizeof(int));
}

// void createArray(struct myarray *a, int t_size, int u_size)
// {
//     a->total_size = t_size;
//     a->used_size = u_size;
//     a->ptr = (int *)malloc(t_size * sizeof(int));
// }

void setVal(struct myarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &(a->ptr)[i]);
    }
}

void getVal(struct myarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    struct myarray arr;
    createArray(&arr, 10, 5);
    setVal(&arr);
    getVal(&arr);

    // Free dynamically allocated memory
    free(arr.ptr);

    // printf("done\n");
    return 0;
}
