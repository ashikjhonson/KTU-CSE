#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    fork();
    fork(); // creates a duplicate child process

    printf("PID: %d\tHello World!\n",getpid()); //getpid() - Process ID
    return 0;
}