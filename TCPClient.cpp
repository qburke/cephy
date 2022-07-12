#include "TCPClient.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

TCPClient::TCPClient() {}
TCPClient::~TCPClient() {}

static int panic(char* msg) {
    printf("CLIENT: %s\n", msg);
    return -1;
}

int TCPClient::send(int port, char *msg, char *resp) {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) return panic("socket creation failed");

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    int r = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if(r < 0) return panic("connect failed");
    
    write(sockfd, msg, sizeof(msg));

    read(sockfd, resp, sizeof(resp));

    close(sockfd);
    
    return 1;
}
