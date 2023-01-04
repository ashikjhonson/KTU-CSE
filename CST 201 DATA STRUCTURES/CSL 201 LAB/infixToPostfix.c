#include <stdio.h>
#include <ctype.h>

char stack[20], in[20],*e, x, a;
int top = -1, size = 20;

int priority(char c)
{
    if(c=='+'||c=='-')      return 1;
    if(c=='*'||c=='/')      return 2;
    if(c=='^')              return 3;
    return 0;
}

void push(char c)
{
    if(top==size-1)     return ;
    else                stack[++top] = c;
}

char pop()
{
    if(top>-1)      return stack[top--];
    else            return '0';
}

void main()
{
    fgets(in,20,stdin);
    push('$');
    e = in;
    while(*e!='\0')
    {
        a = *e;
        if(isalnum(a))      printf("%c",a);

        else if(a=='(')     push(a);

        else if(a==')')     
            while((x=pop())!='(')   printf("%c",x);

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
