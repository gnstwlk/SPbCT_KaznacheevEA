#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "common.h"
 
int main(int argc, char* argv[])
{
    char* service = DEFAULT_SERVICE_PORT;
    char* host = NULL;
    int connfd;
    int nread;
    char buf[MAX_CMDBUF_LEN];
 
    if(argc == 2)
        service = argv[1];
    else if(argc == 3)
    {
        host = argv[1];
        service = argv[2];
    }
    else if(argc > 3)
    {
        fprintf(stderr, "Usage: %s [<host>] [<service | port>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    connfd = create_tcp_socket(host, service, SOCKET_CREATE_CONNECTED);
    if(connfd == -1)
        exit(EXIT_FAILURE);
 
    fputs("Enter comand to execute on server:\n", stdout);
    fputs("> ", stdout);
    fgets(buf, sizeof (buf), stdin);
 
    write(connfd, buf, strlen(buf));
    while((nread = read(connfd, buf, sizeof (buf) - 1)) > 0)
    {
        buf[nread] = '\0';
        fputs(buf, stdout);
    }
    if(nread == -1)
        error_exit("read");
    close(connfd);
    return 0;
}
