#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

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

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int binarySearch(int arr[], int size, int element)
{
    int middle_index = floor(size / 2);
    int last_index = floor(size - 1);
    int first_index = 0;
    while (arr[middle_index] != element & arr[last_index] != element & arr[first_index] != element)
    {
        if (arr[middle_index] < element)
        {
            first_index = middle_index;
            middle_index = floor((last_index + middle_index) / 2);
        }
        else
        {
            last_index = middle_index;
            middle_index = floor(middle_index / 2);
        }
    }
    if (arr[middle_index] == element)
    {
        printf("the element is at the index %d", middle_index);
        return 1;
    }
    else if (arr[first_index] == element)
    {
        printf("the element is at the index %d", middle_index);
        return 1;
    }
    else if (arr[last_index] == element)
    {
        printf("the element is at the index %d", middle_index);
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[100] = {1, 12, 23, 34, 45, 56, 67, 78, 89, 90};
    binarySearch(arr, 10, 67);

    return 0;
}