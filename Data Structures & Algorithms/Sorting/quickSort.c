/*
Quick sort 
@ Ashik 
*/
#include <stdio.h>

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    if(i<j)
    {
        do{i++;}while(arr[i]<pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = pivot;
    arr[l] = temp;
        
    return j;
}

void sort(int arr[], int l, int h)
{
    if(l<h)
    {
        int j = partition(arr, l, h);
        sort(arr, l, j);
        sort(arr, j+1, h);
    }
}

int main()
{
    int n, arr[100], i;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    arr[i] = 100000;
    printf("\nEntered array -->  ");
    for(i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    sort(arr, 0, i);
    printf("\nSorted array -->  ");
    for(i=0; i<n; i++)
        printf("%d\t",arr[i]);
    return 0;
}
