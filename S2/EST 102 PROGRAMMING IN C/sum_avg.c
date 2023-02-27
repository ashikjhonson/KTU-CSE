#include <stdio.h>
void main()
{
    int size, sum = 0;
    float avg;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = sum / size;
    printf("Sum = %d\nAverage = %.2f", sum, avg);
}