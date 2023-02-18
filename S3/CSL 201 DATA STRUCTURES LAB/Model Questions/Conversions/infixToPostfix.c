#include <stdio.h>
#include <ctype.h>
#define size 10

int top = -1;
char c, x, a, *e, expr[size], stack[size];

int priority(char c)
{
    if(c=='^')                  return 3;
    else if(c=='*'||c=='/')     return 2;   
    else if(c=='+'||c=='-')     return 1;
    else                        return 0;
}

void push(char c)
{
    if(top!=size-1)
        stack[++top] = c;
}

char pop()
{
    if(top!=-1)
        return stack[top--];
    else
        return '$';
}

void main()
{
    printf("Enter infix expression: ");
    fgets(expr,size,stdin);
    e = expr;
    while(*e!='\0')
    {
        a = *e;
        if(isalnum(a))
            printf("%c",a);
        else if(a=='(')
            push(a);
        else if(a==')')
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
}