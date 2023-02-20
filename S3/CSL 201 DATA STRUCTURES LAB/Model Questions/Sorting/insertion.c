#include <stdio.h>

int arr[] = {3,4,-2,1,0};

void insertionSort(){
    for(int i=1; i<5; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0&&arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void main()
{
    printf("Array: ");
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);

    insertionSort(arr, 0, 5);

    printf("\nSorted array: ");
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);
}