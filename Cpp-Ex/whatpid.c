#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int status;
    pid_t pid;

    printf("Hello\n");
    pid = fork();
    printf("%d\n", !pid);
    if (pid != 0) {
        if (waitpid(-1, &status, 0) > 0) {
            if (WIFEXITED(status) != 0) {
                printf("%d\n", WEXITSTATUS(status));
            }
        }
    }
    printf("Bye\n");
    exit(3);
}
