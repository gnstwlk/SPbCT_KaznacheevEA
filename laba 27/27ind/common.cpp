#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "common.h"
 
int create_tcp_socket(const char* host, const char* svc, int flag)
{
    struct addrinfo hints;
    struct addrinfo* result;
    struct addrinfo* rp;
    int sfd;
    int ret;
 
    memset(&hints, 0, sizeof (struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if(flag & SOCKET_CREATE_BINDED)
        hints.ai_flags = AI_PASSIVE;
 
    ret = getaddrinfo(host, svc, &hints, &result);
    if(ret != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return -1;
    }
 
    for(rp = result; rp != NULL; rp = rp->ai_next)
    {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if(sfd == -1)
            continue;
 
        if(flag & SOCKET_CREATE_BINDED)
        {
            int on = 1;
            setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof (on));
            if(bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
                break;
        }
        else
        {
            if(!(flag & SOCKET_CREATE_CONNECTED))
                fprintf(stderr, "Warning: improper flag passed to "
                        "craete_tcp_socket(): %d. Assuming SOCKET_CONNECTED (%d)"
                        , flag, SOCKET_CREATE_CONNECTED);
            if(connect(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
                break;
        }
        close(sfd);
    }
 
    if(rp == NULL)
    {
        perror("craete_tcp_socket");
        sfd = -1;
    }
    freeaddrinfo(result);
    return sfd;
}
