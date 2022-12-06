/*
Selection sort 
@ Ashik
*/
#include <stdio.h>
int n, arr[10];

int selectMin(int i)
{
    int min = arr[i];
    int minLoc = i;
    for(int j =i+1; j<n; j++)
        if(min>arr[j])
        {
            min = arr[j];
            minLoc = j;
        }
    return minLoc;
}

void main()
{
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("\nEnter elements\n");
    for(int i =0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEntered array -->  ");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    for(int i=0; i<n; i++)
    {
        int min = selectMin(i);
        if(i!=min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("\nSorted array -->  ");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
