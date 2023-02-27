#include <stdio.h>
int arr[50], n;

void create(int i)
{
    int d;
    if(i<n)
    {
    printf("\nEnter node data: ");
    scanf("%d",&d);
    arr[i]=d;
    printf("\n%d Has left child?(Y-1,N-0): ",arr[i]);
    scanf("%d",&d);
    if(d==1)    create(2*i);
    printf("\n%d Has right child?(Y-1,N-0): ",arr[i]);
    scanf("%d",&d);
    if(d==1)    create(2*i+1);
    }
}

int flag(int key)
{
    for(int i =0; i<n; i++)
        if(arr[i]==key)
            return arr[i];
}

int check(int k)
{
    if(flag(k))
    return 1;
}

void insert()
{
    int k;
    printf("\nEnter data to be inserted: ");
    scanf("%d",&k);
    if(check(k))
    {

    }
}

void main()
{
    printf("\nEnter array size: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        arr[i]=0;
    create(1);
    printf("Binary Tree -->  ");
    for(int i=1; i<n; i++)
    {
        if(arr[i]!=0)
            printf(" %d\t",arr[i]);
        else
            printf(" --\t");
    }
    printf("\nArray Index -->  ");
    for(int i=1; i<n; i++)
        printf("[%d]\t",i);
}