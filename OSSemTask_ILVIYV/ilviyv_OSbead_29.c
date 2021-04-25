#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

static void sig_handler(int);

int main ()
{
    int i, parent_pid, child_pid, status;

    if(signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("Parent: Unable to create handler for SIGUSR1\n");
    if(signal(SIGUSR2, sig_handler) == SIG_ERR)
        printf("Parent: Unable to create handler for SIGUSR2\n");
    parent_pid = getpid();


    if((child_pid = fork()) == 0) {

        for (;;) pause();

    }
    else {
        int run=0;
        do{

        kill(child_pid, SIGUSR1);
        sleep(3);
        kill(child_pid, SIGUSR2);
        sleep(3);
        run++;
        }while(run<3);
        printf("Parent: Terminating child ...\n");
        kill(child_pid, SIGTERM);
        wait(&status);
        printf("Done\n");
    }
}

static void sig_handler(int signo) {

    static int counter=0;
    switch(signo) {
        case SIGUSR1:  /* Incoming SIGUSR1 */
            printf("Child: Received SIGUSER1\n");
            counter++;
            break;
        case SIGUSR2:  /* Incoming SIGUSR2 */
            printf("Child: Received SIGUSER2\n");
            printf("Counter value: %d\n",counter);
            break;
        default: break;
    }
    return;
}
