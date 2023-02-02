#include <stdio.h>
int arr[10], n, k;

int main()
{
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Entered array -->  ");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array -->  ");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}