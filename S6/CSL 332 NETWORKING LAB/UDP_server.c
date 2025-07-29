#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
    int sockfd, new_sock, size;
    char buff[100];
    struct sockaddr_in server_addr, client_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed");
        return 1;
    }
    printf("Socket created successfully!\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Binding failed\n");
        close(sockfd);
        return 1;
    }
    printf("Binding successfull\n");
    if (listen(sockfd, 5) == -1)
    {
        printf("Listen failed\n");
        close(sockfd);
        return 1;
    }
    printf("Server is listening\n");
    size = sizeof(client_addr);
    new_sock = accept(sockfd, (struct sockaddr *)&client_addr, &size);
    if (new_sock == -1)
    {
        perror("Accept failed\n");
        close(sockfd);
        return 1;
    }
    printf("Connection accepted from %s\n", inet_ntoa(client_addr.sin_addr));
    for (;;)
    {
        if (recv(new_sock, buff, sizeof(buff), 0) == -1)

        {
            printf("Receive failed\n");
            close(new_sock);
            close(sockfd);
            return 1;
        }
        if (strcmp(buff, "end") == 0)
        {
            break;
        }
        printf("Client: %s\n", buff);
        printf("Server:");
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = 0;
        if (send(new_sock, buff, sizeof(buff), 0) == -1)
        {
            printf("Error in sending\n");
            close(sockfd);
            return 1;
        }
        if (strcmp(buff, "end") == 0)
        {
            break;
        }
    }
    close(new_sock);
}