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

int partition1(int *arr, int low, int high)
{
    int j = high+1;
    int i = low;
    while (i < j - 1)
    {
        if (arr[i] >= arr[i + 1])
        {
            int a = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = a;
            i++;
        }
        else
        {
            j--;
            int b = arr[i + 1];
            arr[i + 1] = arr[j];
            arr[j] = b;
        }
    }
    j--;
    return j;
}

int partition2(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;
    int temp;

    while (i <= j)
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionindex = partition1(arr, low, high);
        QuickSort(arr, low, partitionindex-1);
        QuickSort(arr, partitionindex+1, high);
    }
    return;
}

int main()
{
    int arr[] = {200, 4, 2, 5, 6, 23, 23, 6334, 5, 34, 57, 868, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // int a;
    // a = partition1(arr, 0, n - 1);
    // printf("%d\n", a);

    QuickSort(arr, 0, n - 1);
    displayArr(arr, n);

    return 0;
}