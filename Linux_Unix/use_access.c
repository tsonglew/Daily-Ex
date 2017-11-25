#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void err_quit(char*);

int main(int argc, char *argv[])  {
    if (argc != 2) {
        err_quit("usage: a.out <pathname>");
        exit(0);
    }
    if (access(argv[1], R_OK) < 0) {
        err_quit("access error");
    } else {
        printf("read access OK\n");
    }

    if (open(argv[1], O_RDONLY) < 0) {
        err_quit("open error");
    } else {
        printf("open for reading OK\n");
    }
    exit(0);
}

void err_quit(char* s) {
    printf("[ERROR] %s\n", s);
}