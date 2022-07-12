#include "TCPServer.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

static void panic(char* msg) {
    printf("SERVER: %s\n", msg);
    exit(-1);
}

TCPServer::TCPServer(int port) {
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) panic("socket creation failed");

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    // reuse address
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse));

    //bind
    int r = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if(r < 0) {
        printf("%d", errno);
        panic("bind failed");
    }
}

void TCPServer::run() {
    //listen
    int r = listen(sockfd, 5);
    if(r < 0)
        panic("listen failed");

    //accept
    struct sockaddr_in cliaddr;
    unsigned int len = sizeof(cliaddr);

    running = 1;
    while(running) {
        int connfd = accept(sockfd, (struct sockaddr *) &cliaddr, &len);
        printf("accepted connection");
        echoHandler(connfd);
    }

}

void TCPServer::stop() {
    running = 0;
}

void TCPServer::echoHandler(int connfd) {
    // echoes data received

    char buf[100];

    memset(buf, 0, 100);

    read(connfd, buf, 100);
    // TODO
    // detect
    // end

    write(connfd, buf, 100);
    close(connfd);
}

TCPServer::~TCPServer() {
   close(sockfd); 
}
