#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>


#define PORT 50001

char buf[]="Sample message.\n";

int main(int argc, char const* argv[])
{
    const int port_number = 12345;
    int sock              = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }
    // setup socket
    struct sockaddr_in server;
    server.sin_family      = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port        = htons(port_number);
    // connect to server
    if ((connect(sock, (struct sockaddr*)&server, sizeof(server))) < 0)
    {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
    // send data to server
    char* hello = "Hello from client";
    send(sock, hello, strlen(hello), 0);
    printf("Message sent to server\n");
    // read data from server
    char buff[1024] = {0};
    recv(sock, buff, sizeof(buff), 0);
    printf("recived message is \"%s\"\n", buff);
    // close connecting socket
    close(sock);
    return 0;
}
