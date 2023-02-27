/*
*Program to implement Queue using Linked List.
*22/11/2022
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
}*head, *new, *ptr, *temp;

void getNode(int data)
{
    new = malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
}

void display()
{
    if(head == NULL)
        printf("Queue is Empty\n");
    else
        {
            ptr = head;
            printf("Queue --> ");
            while(ptr!=NULL)    
                {
                    printf("[%d] ",ptr->data);
                    ptr = ptr->link;
                }
        }
    printf("\n");
}

void Enqueue(int data)
{
    getNode(data);
    if(head == NULL)
        head = new;
    else
    {
        ptr = head;
        while(ptr->link!=NULL)
            ptr = ptr->link;
        ptr->link = new;
    }
    display();
}

void Dequeue()
{
    if(head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
    }
    display();
}

int main()
{
    int c = 0, d;
    while(c<4)
    {
    printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
    scanf("%d",&c);
        switch(c)
        {
            case 1: 
                printf("\nQueue element to be enqueued: ");
                scanf("%d",&d);
                Enqueue(d);
                break;
            case 2:
                printf("\nQueue after dequeueing\n");
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("\nEnter valid option 1/2/3/4");
        }
    }
    return 0;
}
