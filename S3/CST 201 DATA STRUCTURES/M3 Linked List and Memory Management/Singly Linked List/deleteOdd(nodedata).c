/* Program To implement LinkedList Data Structure in C
*  Written by Ashik 23/11/2022
*/
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
}*head, *ptr, *new, *temp, *curr, *prev;

void getNewNode(int data)
{
    new = malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
}

void display() // Display function
{
    printf("\nLinked List\n----------------------------------------------------------\n");
    if(head == NULL)
    {
        printf("\nEmpty\n");
        return;
    }
    ptr = head;
    while(ptr != NULL)
        {
            printf("[%d]  ",ptr->data);
            ptr = ptr->link;
        }
    printf("\n----------------------------------------------------------\n");
}

void insertE(int data) // Function to Insert a node at End
{
    getNewNode(data);
    if(head != NULL)
        {
            ptr = head;
            while(ptr->link != NULL)
                ptr = ptr->link;
            ptr->link = new;
        }
    else
        head = new;
    display();
}

void deletePos(int key) // Function to Delete a specified node
{
    if(head == NULL)
        printf("Empty\n");

        else if(head->data == key)
            {
                temp = head;
                head = head->link;
            }

            else
                {
                prev = head;
                curr = head->link;
                while(curr->data != key)
                    {
                        prev = curr;
                        curr = curr->link;
                        if(curr->link == NULL)
                            break;
                    }
                if(curr->data != key)
                    {
                        printf("Key Not found\n");
                        return;
                    }
                prev->link = curr->link;
                temp = curr;
                }
    free(temp);
    display();
}

void deleteOdd() //Delete elements with odd data
{
    ptr = head;
    while(ptr != NULL)
        {
            if((ptr->data%2) != 0)
                {
                    deletePos(ptr->data);
                    deleteOdd();
                }
            else
                ptr = ptr->link;
        }
}

int main()
{
    int c = 0;
    int data, k;

    while(c<4)
    {
    printf("\nOptions");
    printf("\n1 - Insert element\n2 - Delete Odd data\n3 - Display Linked List\n4 - Exit\n");
    printf("\nEnter choice: ");
    scanf("%d",&c);
    
    switch (c)
    {
    case 1:
        printf("\nEnter data: ");
        scanf("%d",&data);
        insertE(data);
        break;

    case 2:
            deleteOdd();
            break;
        
    case 3:
            display();
            break;
    case 4:
            printf("***Exited successfully***");
            break;
    default:
            printf("\n***Enter valid choice***\n");
            c = 0;
            break;
        }
    }
    return 0;
}
