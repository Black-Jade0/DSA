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

void SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n-1; j++)
        { 
            if(arr[min] > arr[j+1]){
                min = j+1;
            }
        }
        int minval = arr[min];
        arr[min] = arr[i];
        arr[i] = minval;
    }
}

int main()
{
    int arr[] = {2, 4, 2, 5, 6, 23, 23, 6334, 5, 34, 57, 868, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    displayArr(arr, n);

    return 0;
}