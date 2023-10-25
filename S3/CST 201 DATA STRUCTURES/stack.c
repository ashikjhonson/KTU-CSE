/**Program to do stack operation - by Ashik
*******************************************
*******************************************
*******************************************
*******************************************
*/

#include <stdio.h>

int x, n, i, c, top =-1, stack[256];

void push() //push function - to insert element into stack
  {
    if(top>=n-1)
      printf("Stack overflow\n");
    else
     {
      printf("\nEnter element to be pushed into stack: ");
      scanf("%d",&x);
      top++;
      stack[top]=x;
     }
  }


void pop() //pop function - to remove last element in stack
{
  if(top<=-1)
    printf("Stack under flow\n");
  else
   {
    x=stack[top];
    top--;
    printf("Removed element-%d",x);
   }
}

void display() //display function
{
  if(top==-1)
    printf("\nStack is Empty");
  else
   {
    printf("\nStack consists of\n");
    for(i=0; i<=top; i++)
    printf("%d\t",stack[i]);
   }
}

int main()
{
  printf("Enter stack size : ");
  scanf("%d",&n);
  printf("\n1-Push\n2-Pop\n3-Display\n4-Exit");

  do
  {
  printf("\n\nEnter your choice: ");
  scanf("%d",&c);

  switch(c)
    {
	case 1:
		push();
		break;
	case 2:
		pop();
		break;
	case 3:
		display();
		break;
	case 4:
		printf("\nExited program\n");
		break;

	default:
		printf("\nEnter a valid option 1/2/3/4");
    }


  }while(c!=4);

return 0;
}
