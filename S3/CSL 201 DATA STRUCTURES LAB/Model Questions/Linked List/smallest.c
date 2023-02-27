#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
}*head=NULL, *new, *ptr;

struct node* getNode(int data)
{
    new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insertBegin(int data)
{
    new = getNode(data);
    if(head!=NULL)
    {
        new->next = head;
    }
    head = new;
}

void findSmallest()
{
    if(head!=NULL)
    {
        ptr = head;
        int smallest = ptr->data;
        while(ptr)
        {
            if(smallest > ptr->data)
                smallest = ptr->data;
            ptr = ptr->next;
        }
        printf("\nSmallest: %d",smallest);
    }
}

void display()
{
    if(head!=NULL)
    {
        ptr = head;
        while(ptr)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void main()
{
    insertBegin(-3);
    insertBegin(9);
    insertBegin(1);
    insertBegin(7);
    insertBegin(5);
    insertBegin(3);
    
    display();
    findSmallest();
    
}