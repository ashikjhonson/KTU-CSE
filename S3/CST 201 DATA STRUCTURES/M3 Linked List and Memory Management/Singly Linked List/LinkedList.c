/* Program To implement LinkedList Data Structure in C
*  Written by Ashik 17/11/2022
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

void insertB(int data) // Function to Insert a node at Beginnning
{
    getNewNode(data);
    if(head != NULL)
        new->link = head;
    head = new;
    display();
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

void insertPos(int key, int data) // Function to Insert a node after specified node
{
    ptr = head;
    while(ptr->link != NULL)
        {
            if(ptr->data == key)
                break;
            ptr = ptr->link;
        }  
    if(ptr->data != key)
        {
            printf("Key not found\n");
            return;
        }
    getNewNode(data);
    new->link = ptr->link ;
    ptr->link = new;
    display();
}

void deleteB() // Function to Delete a node from front
{
    if(head == NULL)
        printf("Empty\n");
    else
        {
            temp = head;
            head = head->link;
            free(temp);
        }
    display();
}

void deleteE() // Function to Delete a node from end
{
    if(head == NULL)
        printf("Empty\n");
    else
        {
            prev = head;
            curr = head->link;
            while(curr->link != NULL)
                {
                    prev = curr;
                    curr = curr->link;
                }
            temp = curr;
            prev->link = NULL;
            free(temp);
        }
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

int main()
{
    int c = 0, ch = 0;
    int data, k;

    while(c<4)
    {
    printf("\nOptions");
    printf("\n1 - Insert\n2 - Delete\n3 - Display\n4 - Exit\n");
    printf("\nEnter choice: ");
    scanf("%d",&c);
    
    switch (c)
    {
    case 1:
        printf("\n1 - Front\n2 - End\n3 - After specified node");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        printf("\nEnter data: ");
        scanf("%d",&data);

            switch (ch)
            {
                case 1:
                    insertB(data);
                    break;
                case 2:
                    insertE(data);
                    break;
                case 3: 
                    printf("\nEnter Key: ");
                    scanf("%d",&k);
                    insertPos(k,data);
                    break;
                default:
                    printf("\n***Enter valid choice***\n");
                    break;
            }
            break;

    case 2:
            printf("\n1 - Front\n2 - End\n3 - Specified node");
            printf("\nEnter choice: ");
            scanf("%d",&ch);
            switch (ch)
            {
                case 1:
                    deleteB();
                    break;
                case 2:
                    deleteE();
                    break;
                case 3: 
                    printf("\nEnter Key: ");
                    scanf("%d",&k);
                    deletePos(k);
                    break;
                default:
                    printf("\n***Enter valid choice***\n");
                    break;
            }
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
