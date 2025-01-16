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

void merge(int *arr, int low, int mid, int high)
{
    int *merged_array = (int *)malloc((high - low + 1) * sizeof(int));
    int k = 0;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            merged_array[k++] = arr[i++];
        }
        else
        {
            merged_array[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        merged_array[k++] = arr[i++];
        // k++;
        // i++;
    }
    while (j <= high)
    {
        merged_array[k++] = arr[j++];
        // k++;
        // j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = merged_array[i - low];
    }

    free(merged_array);
}

void MergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = ((high + low - 1) / 2);
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {200, 4, 2, 5, 6, 23, 23, 6334, 5, 34, 57, 868, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, n - 1);
    displayArr(arr, n);

    // int arr2[] = {1,2,3,4,2,3,4,5,6};
    // int * result = merge(arr2, 0, 3, 6);
    // displayArr(result, 7);

    return 0;
}