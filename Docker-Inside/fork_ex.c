#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t fpid;
    int count = 0;
    fpid = fork();
    if(fpid < 0) {
        printf("fork error!");
    } else if (fpid == 0) {
        printf("I am child. pid: %d\n", getpid());
    } else {
        printf("I am parent. pid %d\n", getpid());
    }
    return 0;
}
