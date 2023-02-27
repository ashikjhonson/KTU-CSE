//Priority Q - 30/10/22 Ashik Desktop\C


#include <stdio.h>
int size, front=-1, rear=-1, item, p, i;

struct 
{
    int data;
    int priority;
}pq[10];

void enqueue(int item, int p)
{
    if(front==0&&rear==size-1)
        printf("PQ is full");
    else if(front==-1)
    {
    front=rear=0;
    pq[rear].data=item;
    pq[rear].priority=p;
    }
    else if(rear==size-1)
    {
        for(i=front; i<=rear; i++)
            pq[i-1]=pq[i];
        front=front-1;
        rear=rear-1;
        for(i=rear; i>=front; i--)
            {
                if(pq[i].priority<p)
                    break;
            }
        int loc =i+1;
        for(i=rear; i>=loc; i--)
            pq[i+1]=pq[i];
        pq[loc].data=item;
        pq[loc].priority=p;
        rear++;
    }
    else
    {
        for(i=rear; i>=front; i--)
            {
                if(pq[i].priority<p)
                    break;
            }
        int loc =i+1;
        for(i=rear; i>=loc; i--)
            pq[i+1]=pq[i];
        pq[loc].data=item;
        pq[loc].priority=p;
        rear++;
    }
}
void dequeue()
{

    if(front==-1)
        printf("PQ is empty");
    else if(front==rear)
        {
        printf("%d removed ",pq[front].data);
        front=rear=-1;
        }
    else
    {
        printf("%d removed ",pq[front].data);
        front++;
    }

}
void display()
{
    if(front==-1)
        printf("PQ is empty");
    else
    {
        for(i=front; i<=rear; i++)
            printf("%d  ",pq[i].data);
        printf("\n");
        for(i=front; i<=rear; i++)
            printf("%d  ",pq[i].priority);
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
            printf("Enter element & priority: ");
            scanf("%d%d",&item,&p);
            enqueue(item,p);
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