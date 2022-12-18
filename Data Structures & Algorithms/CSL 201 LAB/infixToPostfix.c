#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[15], stack[15], a, s='$', x;
int top = -1, size = 15;

void push(char c)
{
    if(top==size-1)
        return;
    else
        stack[++top] = c;
}

int priority(char c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
    if(c=='^')
        return 3;
    return 0;
}

char pop()
{
    if(top!=-1)
        return stack[top--];
    else
        return '0';
}

void main()
{
    printf("Enter an expression: ");
    fgets(str,15,stdin);
    char *e = str;
    push('$');
    while(*e!='\0')
    {   
        a = *e;

        if(isalnum(a))
            printf("%c",a);

        else if(a=='(')
            push(a);
        
        else if (a==')')
        {
            while((x=pop())!='(')
                printf("%c",x);
        }
        else
        {
            while(priority(stack[top])>priority(a))
                printf("%c",pop());
            push(a);
        }
    e++;
    }
    while((x=pop())!='$')
        printf("%c",x);
}
