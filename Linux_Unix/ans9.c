
// 编写一多进程程序，一个进程输出输出奇数1、3、5、7、9，另一进程输出2、4、6、8、10，如何控制两个进程顺次输出1、2、3、4、5、6、7、8、9、10？

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;
    int fd_arr1[2], fd_arr2[2], i, n;
    pipe(fd_arr1);
    pipe(fd_arr2);
    pid = fork();
    i = 1;
    if(pid == 0) {
        close(fd_arr1[0]);
        close(fd_arr2[1]);
        while(1) {
            read(fd_arr2[0], &i, 1);
            if (i>10) {
                break;
            }
            printf("pid: %d prints %d\n", getpid(), i);
            i += 1;
            write(fd_arr1[1], &i, 1);
        }
        close(fd_arr1[1]);
        close(fd_arr2[0]);
        _exit(0);
    } else {
        close(fd_arr1[1]);
        close(fd_arr2[0]);
        write(fd_arr2[1], &i, 1);
        while(1) {
            read(fd_arr1[0], &i, 1);
            if (i>10) {
                break;
            }
            printf("pid: %d prints %d\n", getpid(), i);
            i += 1;
            write(fd_arr2[1], &i, 1);
        }
        close(fd_arr1[1]);
        close(fd_arr2[0]);
    }
}
