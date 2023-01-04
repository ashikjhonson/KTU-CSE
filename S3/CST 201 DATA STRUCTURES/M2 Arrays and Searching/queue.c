#include <stdio.h>
int front = -1, rear = -1;
int size;
int queue[10];

void enqueue()
{
    if (rear == size - 1)
    {
        printf("\nQueue is full");
        return;
    }
    printf("\nEnter");
}

void dequeue()
{

}

void main()
{
    printf("\nEnter queue size: ");
    scanf("%d",&size);
    enqueue();
    dequeue();
}