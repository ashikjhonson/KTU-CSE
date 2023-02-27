/*
String Palindrome Checker
Written by Ashik 27/11/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    char data;
    struct node *left, *right;
}*head, *new, *ptr, *front, *back;

void getNode(char data)
{
    new = malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right = NULL;
}

void insert(char data)
{
    getNode(data);
    if(head == NULL)
        head = new;
    else
    {
        ptr = head;
        while(ptr->right != NULL)
            ptr = ptr->right;
        
        new->left = ptr;
        ptr->right = new;   
    }
}

void display()
{
    if(head == NULL)
        printf("Empty\n");
        else if(head->right == NULL)
            printf("[ %c ]  ",head->data);
            else
                {
                    ptr = head;
                    while(ptr != NULL)
                    {
                        printf("[ %c ]  ", ptr->data);
                        ptr = ptr->right;
                    }
                }
    printf("\n");
}

bool checkPal() // Function to check plaindrome
{
    front = head; // First node
    back = head; // Last node representation
    while(back->right != NULL)  // Reaches the last node
        back = back->right;
    do
    {
        if(front->data != back->data)
            return false;
        front = front->right;
        back = back->left;
    }while(front!=NULL);
return true;
}

int main()
{
    int i=0;
    char s[100];
    printf("Enter a string\n");
    fgets(s,100,stdin);
    while(i < strlen(s)-1)
    {
        insert(s[i]);
        i++;
    }
    printf("\nEntered string into Linked List -->\t");
    display();
    if(checkPal())
        printf("Palindrome\n");
    else        
        printf("Not Palindrome\n");
    return 0;
}
