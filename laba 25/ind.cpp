#include <stdio.h>
#include <signal.h>
#include <wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int f_in, fd, ppid, pid, N, M, count = 0;

void wakeup()                         //
{
    signal(SIGALRM, wakeup);
    printf("Wake up!\n");
}

void sleeptime(int timeout)
{
    signal(SIGALRM, wakeup);
    alarm(timeout);
    pause();
}

void sigper(int n)
{
    signal(SIGUSR1, sigper);
    printf("KOL-VO BYTE: %d\n", count);
    write(f_in, "1", 1);
    kill(pid, SIGUSR1);
}
void sigchail(int n)
{
    signal(SIGUSR1, sigchail);
    write(f_in, "2", 1);
    kill(ppid, SIGCHLD);
}
int main(int argc, char* argv[])
{
    ppid = getpid();
    if ((f_in = open(argv[1], O_RDONLY)) < 0) {
        ERR("Can't open %s\n", argv[1]);
    }
    N = atoi(argv[2]);

    if (pid = fork() < 0) {
        ERR("Can't fork");
    }
    else if (fork_pid > 0) {
        signal(SIGUSR1, sigper);
        kill(pid, SIGUSR1);
    }
    else {
        pause();
        signal(SIGUSR1, sigchail);
        _exit(-1);
    }
    read(1, &inp, 1);
    putchar(inp);
    close(f_in);
    printf("1");
    return(0);
}
