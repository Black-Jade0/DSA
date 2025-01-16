#include <stdio.h>
#include <stdlib.h>

int displayArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void InsertSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (key < arr[j])
            {
                int a = arr[j];
                arr[j] = key;
                arr[j + 1] = a;
            }
        }
    }
}

void InsertSort2(int *A, int n)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // Loop for each pass
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int arr[] = {2, 4, 2, 5, 6, 23, 23, 6334, 5, 34, 57, 868, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, n);
    displayArr(arr, n);
    return 0;
}