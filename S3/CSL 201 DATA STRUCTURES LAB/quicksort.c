#include <stdio.h>

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int pIndex = l;

    for(int i=l; i<h; i++)
    {
        if(arr[i]<=pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;

            pIndex++;
        }
    }

    int temp = arr[h];
    arr[h] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void quicksort(int arr[], int l, int h)
{
    if(l<h)
    {
        int j=partition(arr, l, h);
        quicksort(arr, l, j-1);
        quicksort(arr, j+1, h);
    }
}

void main()
{
    int arr[] = {0,2,3,1,4};
    printf("Array: ");
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);
    quicksort(arr, 0, 5);
    printf("\nSorted array: ");
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);
}