#include <iostream>
#include <sys/types.h>
#include <unistd.h>

void unix_error(char *msg) {
    fprintf(stderr, "%s, %s\n", msg, strerror(errorno));
    exit(0);
}

pid_t Fork(void) {
    pid_t pid;
    if((pid = fork()) < 0){
        unix_error("Fork Error");
    }
    return pid;
}

pid = Fork();
