#include <stdio.h>
#include <stdlib.h>

int displayArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    return 0;
}

void CountSort1(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n;)
    {
        if (arr[max] < arr[i])
        {
            max = i;
            i++;
        }
        else
        {
            i++;
        }
    }
    int max_val = arr[max];

    int size = max_val + 1;

    // int max = arr[0]; // Initialize max with the first element of the array
    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }

    // int size = max + 1;

    int *table;
    table = (int *)calloc((size), sizeof(int));

    for (int i = 0; i < size; i++) // initialising with 0
    {
        table[i] = 0;
    }

    for (int i = 0; i < n; i++) // counting the occurance of each element and appending one at that index value
    {
        table[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < size;)
    {
        if (table[i] == 0)
        {
            i++;
        }
        else if (table[i] > 0)
        {
            arr[index] = i;
            index++;
            table[i]--;
        }
    }

    free(table);
}

int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void CountSort2(int *A, int n)
{
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n);

    // Create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array A

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {200, 4, 2, 5, 6, 23, 23, 6334, 5, 34, 57, 868, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    CountSort1(arr, n);
    displayArr(arr, n);

    return 0;
}