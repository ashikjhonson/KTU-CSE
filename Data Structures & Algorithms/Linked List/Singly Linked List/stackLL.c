/*Program to implement Stack using Linked List*/

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
        printf("Stack Empty\n");
    else
        {
            ptr = head;
            printf("Stack --> ");
            while(ptr!=NULL)    
                {
                    printf("[%d]",ptr->data);
                    ptr = ptr->link;
                }
        }
    printf("\n");
}

void push(int data)
{
    getNode(data);
    if(head != NULL)
    {
        new->link = head;
    }    
    head = new;
    display();
}

void pop()
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
    int c=0, d;
    while(c<4)
    {
    printf("\n1-Push\n2-Pop\n3-Display\n4-Exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1: 
            printf("\nEnter element to be pushed: ");
            scanf("%d",&d);
            push(d);
            break;
        case 2:
            printf("\nStack after doing pop operation\n");
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
    }
    }
    return 0;
}
