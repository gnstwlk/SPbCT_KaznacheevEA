#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "common.h"
 
void child_proc(int fd)
{
    char buf[MAX_CMDBUF_LEN];
    char* ptr = buf;
    ssize_t nread = 0;
    size_t curlen = 0;
 
    while(curlen < sizeof (buf))
    {
        nread = read(fd, ptr, sizeof (buf) - curlen);
        if(nread == -1)
            error_exit("read");
        if(nread == 0)
        {
            fputs("Client disconnected. Ignoring request.", stderr);
            exit(EXIT_SUCCESS);
        }
        curlen += nread;
        if(ptr[nread - 1] == '\n')
            break;
        ptr += nread;
    }
 
    if(buf[curlen - 1] != '\n')
    {
        write(fd, "Command is too long.", strlen("Command is too long."));
        exit(EXIT_SUCCESS);
    }
    buf[curlen - 1] = '\0';
 
    if(dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
 
    execlp(buf, buf, NULL);
    error_exit("execlp");
}
 
int main(int argc, char* argv[])
{
    struct sigaction sa;
    char* service = DEFAULT_SERVICE_PORT;
    char* host = NULL;
    pid_t child;
    int listenfd, connfd;
 
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
 
    sa.sa_flags = SA_RESTART | SA_NOCLDWAIT;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = SIG_DFL;
    if(sigaction(SIGCHLD, &sa, NULL) == -1)
        error_exit("sigaction");
 
    listenfd = create_tcp_socket(host, service, SOCKET_CREATE_BINDED);
    if(listenfd == -1)
        exit(EXIT_FAILURE);
 
    if(listen(listenfd, 0) == -1)
        error_exit("listen");
 
    for(;;)
    {
        connfd = accept(listenfd, NULL, NULL);
        if(connfd == -1)
        {
            if(errno == EINTR)
                continue;
            error_exit("accept");
        }
 
        child = fork();
        if(child == -1)
            error_exit("fork");
        if(child == 0)
        {
            close(listenfd);
            child_proc(connfd);
            exit(EXIT_SUCCESS); /* сюда мы никогда не попадем, но для наглядности напишем */
        }
 
        close(connfd);
    }
    return (EXIT_SUCCESS);
}
