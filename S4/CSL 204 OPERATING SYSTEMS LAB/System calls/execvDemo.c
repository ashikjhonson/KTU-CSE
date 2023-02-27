#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Inside execvDemo, PID: %d\n",getpid());
    char *args[]={"1", "2", NULL};
    execv("./execv2nd",args);
    return 0;
}