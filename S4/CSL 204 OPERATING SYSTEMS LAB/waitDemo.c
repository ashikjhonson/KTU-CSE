#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p = fork();

    if(p==0)
    {
        printf("Inside child's process, PID: %d\n",getpid());
    }
    else
    {
        wait(NULL);
        printf("Inside parent's process, PID: %d\n",getpid());
    }

    return 0;
}