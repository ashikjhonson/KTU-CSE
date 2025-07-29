#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
    char filename[24];
    FILE *fp;
    char buffer[100];
    int socketid, new_sock, i = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    socketid = socket(AF_INET, SOCK_STREAM, 0);
    if (socketid == -1)
    {
        printf("Socket creation failed\n");
        return 1;
    }
    printf("Server socket created successfully\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(socketid, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Bind failed\n");
        close(socketid);
        return 1;
    }
    printf("Bind successful\n");
    if (listen(socketid, 5) < 0)
    {
        printf("Listen failed\n");
        close(socketid);
        return 1;
    }
    printf("Waiting for incoming connections...\n");
    addr_size = sizeof(client_addr);
    new_sock = accept(socketid, (struct sockaddr *)&client_addr, &addr_size);
    if (new_sock < 0)
    {
        printf("Accept failed\n");
        close(socketid);
        return 1;
    }
    printf("Connection accepted\n");
    int received = recv(new_sock, filename, sizeof(filename), 0);
    if (received <= 0)
    {

        printf("Receiving message failed or connection closed\n");
    }
    printf("yes0\n");
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("the file doesn't exist\n");
        close(new_sock);
        close(socketid);
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
        send(new_sock, buffer, strlen(buffer), 0);
        printf("%d\n", i);
        i++;
        bzero(buffer, sizeof(buffer));
    }
    printf("yes1\n");
    close(new_sock);
    close(socketid);
    printf("yes1\n");
}