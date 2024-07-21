#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5000
  
int main() 
{    
    char buffer[100];
    char *message = "Hello Client\0";
    int listenfd, len;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));

    int accepted = 0;

    listenfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    len = sizeof(cliaddr);
   
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
    
    while (accepted == 0) {
        int n = recvfrom(listenfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr, &len);
        buffer[n] = '\0';

        if (strcmp(buffer, "Number405\n") == 0) {
            printf("good to go\n");
            accepted = 1;
            sendto(listenfd, message, strlen(message), 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
        }
    }
} 