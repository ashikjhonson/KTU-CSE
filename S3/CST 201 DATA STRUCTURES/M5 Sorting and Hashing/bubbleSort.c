/*
Bubble sort 
@ Ashik
*/
#include <stdio.h>

int main()
{
    int n, arr[100];
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("\nEntered array -->  ");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    int temp;
    for(int j=1; j<n; j++)
    {
        for(int k=0; k<n-j; k++)
        {
            if(arr[k]>arr[k+1])
            {
                temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
    printf("\nSorted array -->  ");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    return 0;
}
