#include <stdio.h>
#define SIZE 5

int arr[] = {4, 2, 5, 1, 8};

void merge(int arr[], int lb, int mid, int ub)
{
    int b[SIZE];
    int i = lb, k = lb;
    int j = mid + 1;

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            k++;
            i++;
        }
    }
    for (int i = lb; i <= ub; i++)
    {
        arr[i] = b[i];
    }
}

void mergesort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void main()
{
    printf("\n Array -->  ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    mergesort(arr, 0, 4);
    printf("\n\n Sorted array -->  ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
}