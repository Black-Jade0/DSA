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

int deletionArr(int arr[], int index,int size)
{

    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }

    return 1;
}

int main()
{
    int arr[10]={1,2,3,4,5};
    displayArr(arr,5);
    deletionArr(arr,2,5);
    displayArr(arr,4);
    return 0;
}