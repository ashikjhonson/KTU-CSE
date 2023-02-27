#include <stdio.h>
#define size 5

void merge(int arr[], int lb, int mid, int ub)
{
    int i=lb, k=lb, j=mid+1, B[size];

    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            B[k] = arr[i];
            k++;i++;
        }
        else
        {
            B[k] = arr[j];
            k++;j++;
        }
    }

    if(i > mid)
    {
        while(j<=ub)
        {
            B[k] = arr[j];
            k++;j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            B[k] = arr[i];
            k++;i++;
        }
    }

    for(int i=lb; i<=ub; i++)
        arr[i] = B[i];
}

void mergesort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
    mergesort(arr, lb, mid);
    mergesort(arr, mid+1, ub);
    merge(arr, lb, mid, ub);
    }
}

void main()
{
    int arr[] = {3,2,5,1,4};
    mergesort(arr, 0, 4);
    printf("Sorted array: ");
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
}