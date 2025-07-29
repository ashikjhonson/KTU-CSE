#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main() {
char filename[100];
FILE *fp;
char buffer[100];
int socketid;
struct sockaddr_in server_addr;
socketid = socket(AF_INET, SOCK_STREAM, 0);
if (socketid == -1) {
printf("Socket creation failed\n");
return 1;
}
printf("Client socket created successfully\n");
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
if (connect(socketid, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
printf("Connection failed\n");
close(socketid);
return 1;
}
printf("Connected to server\n");

printf("enter the name of the file\n");
scanf("%s",filename);
if (send(socketid, filename, strlen(filename), 0) == -1) {
printf("Send failed\n");
}
fp=fopen(filename,"w");
if(fp==NULL){
printf("file creation failed\n");
}
while(recv(socketid, buffer, sizeof(buffer), 0)>0){
printf("%s\n",buffer);
fputs(buffer,fp);
bzero(buffer,sizeof(buffer));
}
close(socketid);
}