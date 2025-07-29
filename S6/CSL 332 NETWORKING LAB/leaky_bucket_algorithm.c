#include <stdio.h>
void main()
{
    int inc, bsize, store = 0, out, n;
    printf("enter the bucket size,number of packets,outgoing rate\n");
    scanf("%d%d%d", &bsize, &n, &out);
    while (n != 0)
    {
        printf("enter the number of incoming packets\n");
        scanf("%d", &inc);
        if (inc <= bsize - store)
        {
            store += inc;
            printf("number of packets currently in the bucket is %d\n", store);
        }
        else
        {
            printf("maximum bucket size reached dropping packets %d\n", inc - (bsize - store));
            store += bsize - store;
            printf("bucket buffer size is %d out of %d\n", store, bsize);
        }
        store = store - out;
        printf("bucket size after outgoing %d\n", store);
        printf("remaining space in bucket %d\n", bsize - store);
        n--;
    }
}