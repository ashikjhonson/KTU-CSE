//Insertion sort
//by navendu c

#include <stdio.h>

void display(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
  //int i;
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}


void main() {
  int arr[10],size,i;
  printf("Enter array size\n");
  scanf("%d",&size);
  printf("Enter the elements\n");
  for ( i = 0; i < size; i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Array before sorting\n");
  display(arr,size);
  insertionSort(arr, size);
  printf("Sorted array:\n");
  display(arr, size);
}
