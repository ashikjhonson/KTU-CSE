#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("sample.txt", O_RDWR);
    char msg[20] = "Hello World!";
    char buf[100];
    printf("fd: %d\n", fd);

    if(fd!=-1){
        printf("Opened\n");
        write(fd, msg, sizeof(msg));
        lseek(fd, 0, SEEK_SET);
        read(fd, buf, sizeof(msg));
        printf("%s", buf);
        close(fd);
    }
    return 0;
}