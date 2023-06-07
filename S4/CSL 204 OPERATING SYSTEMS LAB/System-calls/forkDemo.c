#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    fork();
    printf("Hello World!\n");
    return 0;
}