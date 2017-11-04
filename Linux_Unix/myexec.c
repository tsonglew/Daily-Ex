#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXLINE 4096

static void sig_int(int); /* signal catching function */

int main(void) {
        char buf[MAXLINE];
        // The pid_t data type represents process IDs. 
        // You can get the process ID of a process by calling getpid.
        // The function getppid returns the process ID of the parent of the current process
        // (this is also known as the parent process ID). 
        // Your program should include the header files unistd.h and sys/types.h to use these functions.
        pid_t pid;
        int status;

        // SIGINT: interruption signal
        if (signal(SIGINT, sig_int) == SIG_ERR) {
                printf("signal error\n");
        }
        printf("%% "); /* print prompt */
        while (fgets(buf, MAXLINE, stdin) != NULL) {
                if (buf[strlen(buf) - 1] == '\n') {
                        buf[strlen(buf) - 1] = 0;
                }
                if ((pid = fork()) < 0) {
                        printf("fork error\n");
                        exit(0);
                }
                else if (pid == 0) { /* for child */
                        int res = execlp(buf, buf, (char *)0);
                        if (res == 0)
                        {
                                printf("could not execute: %s", buf);
                                exit(127);
                        }
                }
                if ((pid = waitpid(pid, &status, 0)) < 0) {
                        printf("waitpid error");
                }
                printf("%% ");
        }
        return 0;
}

void sig_int(int signo) {
        printf("interrupt\n%% ");
}