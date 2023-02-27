#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    fork();
    fork();

    printf("PID: %d\tHello World!\n",getpid());
    return 0;
}