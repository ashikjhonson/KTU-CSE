#include <stdio.h>
int cq[256];
int front=-1, rear=-1, size, item;

void enqueue()
{
    if((front==0&&size==rear-1)||(front==rear+1))
        printf("CQ is full");
    else
    {
        printf("Enter element ");
        scanf("%d",&item);
        if(front==-1)
            front=0;
        rear=(rear+1)%size;
        cq[rear]=item;
    }
}

void dequeue()
{
    if(front==-1)
        printf("Empty");
    else
    {
        item=cq[front];
        if(front==rear)
            front=rear=-1;
        else
        {
            front=(front+1)%size;
            printf("Deleted %d",cq[front]);
        }
    }
}

void display()
{
    int i;
    if(front==-1)
        printf("Empty");
    else
    {
        printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % size) {
      printf("%d ", cq[i]);
    }
    printf("%d ", cq[i]);
    printf("\n Rear -> %d \n", rear);
    }
}

int main()
{
   printf("Enter queue size: ");
    scanf("%d",&size);
    int c = 0;
    printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
    while(c<4)
    { 
        printf("\nEnter choice: ");
        scanf("%d",&c);

        switch (c)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;
}