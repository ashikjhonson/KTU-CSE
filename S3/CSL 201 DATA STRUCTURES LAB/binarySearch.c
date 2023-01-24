#include <stdio.h>
int arr[10], n, beg, mid, end, k;

int main()
{
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(int i = 0; i<n; i++)
        scanf("%d",&arr[i]);
    
    for(int j = 1; j<n; j++)
        for(int k = 0; k<n-j; k++)
        {
            if(arr[k]>arr[k+1])
            {
                int  temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }

    printf("Enter element to be searched: ");
    scanf("%d",&k);
    beg = 0;
    end = n-1;
    while(beg<=end)
    {
        mid = (beg+end)/2;

        if(arr[mid]==k)
        {
            printf("Element found at index %d",mid);
            return 0;
        }
        else if(arr[mid]<k)     beg = mid+1;
        else    end = mid-1;
    }
    printf("Element not found");
    return 0;
}