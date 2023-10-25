#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Inside 2nd process, PID: %d\n",getpid());
    return 0;
}