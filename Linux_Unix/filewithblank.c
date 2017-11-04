#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH 

void exit_err(char*) __attribute__((noreturn)); 

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {
        int fd;
        if ((fd=creat("file.hole", FILE_MODE)) < 0) {
                exit_err("create file error!");
        }
        if (write(fd, buf1, 10) != 10) {
                exit_err("write file error!");
        }
        if (lseek(fd, 16384, SEEK_SET) == -1) {
                exit_err("lseek error!");
        }
        if (write(fd, buf2, 10) != 10){
                exit_err("write buf2 error!");
        }
}

void exit_err(char *s) {
        printf("[ERROR]%s\n", s);
        exit(1);
}