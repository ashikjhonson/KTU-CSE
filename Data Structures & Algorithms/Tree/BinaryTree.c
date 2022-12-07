/*
* @author Ashik
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create()
{
    int d;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->left = new->right = NULL;
    printf("\nEnter node data: ");
    scanf("%d",&d);
    if(d==0)   
        return 0;
    new->data = d;
    printf("\n%d has left child? (Yes - 1 or No - 0): ",new->data);
    scanf("%d",&d);
    if(d==1)    new->left = create();
    printf("\n%d has right child? (Yes - 1 or No - 0): ",new->data);
    scanf("%d",&d);
    if(d==1)    new->right = create();
    return new;
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("[%d]  ",root->data);
        inorder(root->right);
    }
}

void main()
{
    struct node* root;
    root = create();
    inorder(root);
}
