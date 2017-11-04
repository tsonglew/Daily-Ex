#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main() {
        printf("sysconf host name max: %ld\n", sysconf(_POSIX_CHILD_MAX));
        printf("pathconf host name max: %ld", pathconf("/", _POSIX_CHILD_MAX));
        return 0;
}