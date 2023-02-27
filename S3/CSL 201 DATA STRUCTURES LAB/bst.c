#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
} *root = NULL, *new;

struct node *createNode(int data)
{
    new = malloc(sizeof(struct node));
    new->left = new->right = NULL;
    new->data = data;
    return new;
}

struct node *makeTree(struct node *root, int data)
{
    if (root == NULL)
        root = createNode(data);
    else if (root->data > data)
        root->left = makeTree(root->left, data);
    else if (root->data < data)
        root->right = makeTree(root->right, data);
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void main()
{
    root = makeTree(root, 5);
    root = makeTree(root, 3);
    root = makeTree(root, 8);
    root = makeTree(root, 1);
    root = makeTree(root, 4);
    inorder(root);
}