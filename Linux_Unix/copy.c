#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main(void) {
        int n;
        char buf[BUFFSIZE];

        while((n=read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
                if(write(STDOUT_FILENO, buf, n) != 0) {
                        printf("write error");
                }
        }
        if (n < 0) {
                printf("read error");
        }
        return 0;
}