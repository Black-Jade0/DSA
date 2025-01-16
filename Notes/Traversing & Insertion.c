#include<stdio.h>
#include<stdlib.h>

int traverseArr(int arr[],int n){

    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
    
}

int insertionArr(int arr[],int element,int index,int capacity,int size){
    if (size >= capacity){
        return -1;
    }
    else{
        for (int i =  (size-1); i >= index; i--)
        {
            arr[i+1] = arr[i];
        }
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[10]={1,3,5,6,8};
    traverseArr(arr,5);
    insertionArr(arr, 9,2,10,5);
    traverseArr(arr,6);
    
    if (insertionArr){
        printf("Complete ....insertion");
    }
    else{
        printf("Error in insertion");
    }

    return 0;
}