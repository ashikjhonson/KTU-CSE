#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 20

char s[max], c, stack[max];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

bool isEmpty()
{
    return top==-1;
}

bool isValid(char *s)
{
    for(int i=0; i<strlen(s); i++)
    {
        c = s[i];

        if(c=='(' || c=='{' || c=='[')
            push(c);
        else
        {
            if(isEmpty())
                return false;
            
            char top_c = pop();

            if(c==')'&&top_c!='(')
                return false;
            if(c=='}'&&top_c!='{')
                return false;
            if(c==']'&&top_c!='[')
                return false;
        }
    }
    return isEmpty();
}

void main()
{
    printf("Enter a string: ");
    scanf("%s",s);

    if(isValid(s))
        printf("\nValid");
    else
        printf("\nNot");
}