#include "TCPServer.h"
#include "TCPClient.h"

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    TCPServer *server = new TCPServer(3000); 
    if(fork() == 0) {
        server->run();
    }
    else {
        TCPClient client = TCPClient();
        char *msg = "hello";
        char res [100];
        int r = -1;
        while(r == -1) {
            r = client.send(3000, msg, res);
            sleep(1);
        }
        printf("%s", res);
        server->stop();
    }
}
