#include <sys/types.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#define TIMEOUT 10 
int f1(int), f2(int), f3(int); 
int pid0, pid1, pid2;
void main(void) { 
    setpgrp();
    pid0 = getpid();
    pid1 = fork();
if (pid1 == 0) /* process 1 */ { 
    signal(SIGUSR1, f1);
pid1 = getpid();
pid2 = fork();
if (pid2 < 0 ) puts("Fork error");
if (pid2 > 0) for(;;);
else /* process 2 */
                {signal(SIGUSR2, f2); pid2 = getpid();
                kill(pid1,SIGUSR1); 
                for (;;);
    } 
}
else /* process 0 */
{ signal(SIGALRM, f3);
alarm(TIMEOUT); 
pause();
}
exit(0);
}
int f1(int signum)
{ signal(SIGUSR1, f1);
printf("Process 1 (%d) has got a signal from process 2 (%d)\n",pid1,pid2);
sleep(1);
kill(pid2, SIGUSR2);
return 0;
}
int f2(int signum)
{ signal(SIGUSR2, f2);
printf("Process 2 (%d) has got a signal from process 1 (%d)\n",pid2,pid1);
sleep(1);
kill(pid1, SIGUSR1);
return 0;
}
int f3(int signum)
{ printf("End of job - %d\n", pid0);
kill(0, SIGKILL);
return 0;
}
