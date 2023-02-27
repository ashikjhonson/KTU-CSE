#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
}*root=NULL, *new, *curr, *temp;

struct node* insert(struct node* root, int data)
{
    new = malloc(sizeof(struct node));
    new->data = data; 
    new->left = new->right = NULL;

    if(!root)
        root = new;
    else
    {
        if(root->data > data)
            root->left = insert(root->left, data);
        else if(root->data < data)
            root->right = insert(root->right, data);
    }
    return root;
}

struct node* min(struct node* root)
{
    curr = root;
    while(curr&&curr->left)
        curr = curr->left;
    return curr;
}


struct node* delete(struct node* root, int data)
{
    if(!root)
        root = NULL;
    else if(root->data > data)
        root->left = delete(root->left, data);
    else if(root->data < data)
        root->right = delete(root->right, data);
    else
    {
        if(!root->left&&!root->right)
        {
            free(root);
            root = NULL;
        }
        else if(!root->left)
        {
            temp = root;
            root = root->right;
            free(temp);
        }
        else if(!root->right)
        {
            temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main()
{
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = delete(root, 10);
    inorder(root);
}