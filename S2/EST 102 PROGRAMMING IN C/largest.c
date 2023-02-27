#include <stdio.h>
void main()
{
    int a, b, c;
    printf("Enter values of\n");
    printf("\nNumber 1: ");
    scanf("%d", &a);
    printf("\nNumber 2: ");
    scanf("%d", &b);
    printf("\nNumber 3: ");
    scanf("%d", &c);
    int largest = a > b ? a : b;
    largest = largest > c ? largest : c;
    printf("\nLargest = %d", largest);
}