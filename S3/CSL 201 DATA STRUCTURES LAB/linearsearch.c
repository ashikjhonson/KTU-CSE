#include <stdio.h>
int arr[10], n, k;
 
int main()
{
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(int i = 0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("Enter element to be searched: ");
    scanf("%d",&k);
    for(int i = 0; i<n; i++)
    {
        if(arr[i]==k)
        {
            printf("Element found at index %d",i);
            return 0;
        }
    }
    printf("Element not found");
    return 0;
}
