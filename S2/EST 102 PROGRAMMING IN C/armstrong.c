#include <stdio.h>
void main()
{
    int n, remainder, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    int x = n;
    while (n)
    {
        remainder = n % 10;
        sum += remainder * remainder * remainder;
        n /= 10;
    }
    if (x == sum)
        printf("Armstrong");
    else
        printf("Not Armstrong");
}