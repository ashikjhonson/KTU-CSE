#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
int main()
{
    int s;
    char buff[100];
    struct sockaddr_in server_addr;
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1)
    {
        printf("Creation failed\n");
        close(s);
        return 1;
    }
    printf("Socket created successfully\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (connect(s, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Connection Failed\n");
        close(s);
        return 1;
    }
    printf("Connection Successful\n");
    for (;;)
    {
        printf("Client:");
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = 0;
        if (send(s, buff, sizeof(buff), 0) == -1)
        {
            printf("Error in sending\n");
            close(s);
            return 1;
        }
        if (strcmp(buff, "end") == 0)
        {
            break;
        }
        if (recv(s, buff, sizeof(buff), 0) == -1)
        {
            printf("Receive failed\n");
            close(s);
            return 1;
        }
        printf("Server: %s\n", buff);
        if (strcmp(buff, "end") == 0)
        {
            break;
        }
    }
    close(s);
    return 0;
}