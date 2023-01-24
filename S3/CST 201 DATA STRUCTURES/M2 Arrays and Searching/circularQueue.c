#include <stdio.h>
int cq[10];
int front=-1, rear=-1;
int size, c=0;

void enqueue()
{
    if(front==-1)
    {
        
    }
}

void main()
{
    printf("Enter queue size: ");
    scanf("%d",&size);
    printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit");

    do
    {
    printf("\n\nEnter your choice: ");
    scanf("%d",&c);

    switch(c)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExited program\n");
            break;

        default:
            printf("\nEnter a valid option 1/2/3/4");
        }


    }while(c!=4);
}