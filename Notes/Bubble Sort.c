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

int *BubbleSort(int *arr, int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }
    return arr;
}

//   //    updated version  by me

int *BubbleSort2(int *arr, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }
    return arr;
}

// version of sir

void BubbleSort3(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i + 1);
        for (int j = 0; j < n - i - 1; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int A[], int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {2, 4, 2, 5, 6,23,23,6334,5,34,57,868, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("size is %d\n", n);
    BubbleSort(arr, n);
    displayArr(arr, n);
    // displayarr(arr);
    // printf("%d\n",arr[0]);
    // printf("%d\n",arr[1]);
    // printf("%d\n",arr[2]);
    // printf("%d\n",arr[3]);
    // printf("%d\n",arr[4]);
    // printf("%d\n",arr[5]);
    // printf("%d\n",arr[6]);

    // int n = sizeof(arr) / sizeof(arr[0]);
    // printf("%d\n",n);
    return 0;
}