#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void) {
        umask(011);
        if (creat("foo", RWRWRW) < 0) {
                printf("create error for foo");
        }
        umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        if (creat("bar", RWRWRW) < 0) {
                printf("create error for bar");
        }
        exit(0);
}