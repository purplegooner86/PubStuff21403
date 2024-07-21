#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <stdlib.h>

#include <pthread.h>



#define SERVER_PORT 5000
#define SERVER_ADDR "127.0.0.1"
#define SLEEP_TIME 0.002


int has_recieved = 0;


typedef struct {
    int sockfd;
    char** recv_buffer;
} thread_data_t;

void* socketListener(void* vargp) {
    thread_data_t* data = (thread_data_t*)vargp;

    recvfrom(data->sockfd, *(data->recv_buffer), 1024, 0, (struct sockaddr*)NULL, NULL);

    has_recieved = 1;

    return NULL;
}

int main() {
    int i;
    int sockfd;
    char* recv_buffer = calloc(1024, sizeof(char));
    char out_buffer[33] = { 0 };

    thread_data_t data_for_thread = { 0 }; 

    struct sockaddr_in servaddr; 

    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    servaddr.sin_port = htons(SERVER_PORT); 
    servaddr.sin_family = AF_INET;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    pthread_t thread_id;

    data_for_thread.recv_buffer = &recv_buffer;
    data_for_thread.sockfd = sockfd;

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
    { 
        printf("\n Error : Connect Failed \n"); 
        exit(0); 
    }


    pthread_create(&thread_id, NULL, socketListener, (void*)&data_for_thread);
    printf("Thread Created. Firing...\n");

    for (i = 0; i < 500; i++) {
        sleep(SLEEP_TIME);
        if (has_recieved == 1) {
            break;
        }

        sprintf(out_buffer, "Number%d\n", i);
        sendto(sockfd, out_buffer, 1024, 0, (struct sockaddr*)NULL, sizeof(servaddr)); 
    }

    printf("i = %d\n", i);

    pthread_join(thread_id, NULL);
    close(sockfd);

    return 0;
}