#include <stdio.h>

int arr[] = {-3,2,5,1,0};

void selectionSort()
{
    for(int i=0; i<4; i++)
    {
        int minLoc = i;
        for(int j=i+1; j<5; j++)
            if(arr[j]<arr[minLoc])
                minLoc = j;
        
        if(minLoc!=i)
        {
            int temp = arr[minLoc];
            arr[minLoc] = arr[i];
            arr[i] = temp;
        }
    }
}

void main()
{
    printf("Array: ");
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);

    selectionSort(arr, 0, 5);

    printf("\nSorted array: ");
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);
}