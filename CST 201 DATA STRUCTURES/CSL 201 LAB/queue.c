#include <stdio.h>
int q[10], size, front =-1, rear =-1;

void display()
{
    if(rear==-1)
        printf("Queue Empty");
    else
    {
        printf("\nQueue\n\n");
        for(int i =front; i<=rear; i++)
            printf("| %d |\t",q[i]);
    }   
}

void enq(int data)
{
    if(rear == size-1)
        printf("\nQueue is full");
    else
    {
        if(front==-1)   front = 0;
        q[++rear] = data;
    }
}

void deq()
{
    if(front==-1||rear==-1)
        printf("\nQueue is empty");
    else
    {
        printf("Removed %d",q[front++]);
        if(front>rear)
            front = rear =-1;
    }
}

void main()
{
    int c=0, d;
    printf("Enter queue size: ");
    scanf("%d",&size);
    printf("\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\nOTHER-EXIT");
    while(c<4)
    {
        printf("\nEnter your choice -->  ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d",&d);
                enq(d);
                break;
            case 2: 
                deq();
                break;
            case 3:
                display();
                break;
            default:
                break;
        }
    }
}