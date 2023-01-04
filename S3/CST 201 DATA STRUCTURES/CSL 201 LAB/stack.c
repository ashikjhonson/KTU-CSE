#include <stdio.h>
int stack[10], top =-1, size;

void display()
{
    if(top>-1)
    {
        printf("\nStack\n\n");
        for(int i =top; i>=0; i--)
            printf("| %d |\n",stack[i]);
    }
    else    
        printf("Stack Empty");
}

void push(int data)
{
    if(top<size-1)
    {
        stack[++top] = data;
        display();
    }
    else    
        printf("Stack overflow\n");
}

void pop()
{
    if(top>-1)
        printf("%d Removed\n",stack[top--]);
    else
        printf("Stack underflow\n");
}

void main()
{
    int c=0, d;
    printf("Enter stack size: ");
    scanf("%d",&size);
    printf("\n1-PUSH\n2-POP\n3-DISPLAY\nOTHER-EXIT");
    while(c<4)
    {
        printf("\nEnter your choice -->  ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d",&d);
                push(d);
                break;
            case 2: 
                pop();
                break;
            case 3:
                display();
                break;
            default:
                break;
        }
    }
}