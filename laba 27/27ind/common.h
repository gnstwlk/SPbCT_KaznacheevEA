#ifndef COMMON_H
#define COMMON_H
 
#define SOCKET_CREATE_BINDED    (1 << 0)
#define SOCKET_CREATE_CONNECTED (1 << 1)
 
#define DEFAULT_SERVICE_PORT ("12345")
 
#define MAX_CMDBUF_LEN (1024)
 
#define error_exit(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)
 
#ifdef __cplusplus
extern "C"
{
#endif
 
extern int create_tcp_socket(const char* host, const char* svc, int flag);
 
#ifdef __cplusplus
}
#endif
 
#endif
