// 编写一个程序，模拟猜数字游戏，第1个进程负责随机给出1~100之间的一个整数，
// 第2个进程负责猜出这个数，第2个进程猜数时，第1个线程给出“大了”、“小了”的回答。

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int guess_int(int a, int b);

int main() {
    pid_t pid;
    int fd_arr1[2], fd_arr2[2];
    pipe(fd_arr1);
    pipe(fd_arr2);

    pid = fork();
    if(pid==0) {
        srand(time(NULL));
        // child process
        close(fd_arr1[0]);
        close(fd_arr2[1]);
        char guess = -1;
        char judge_res = -1;
        char rand_int = (char)guess_int(1, 100);
        printf("answer rand_int: %d\n", (int)rand_int);

        while((int)judge_res != 0) {
            read(fd_arr2[0], &guess, 1);
            printf("guess: %d", guess);
            if(guess == rand_int) {

                judge_res = 0;
                printf("equal!\n");
            } else if(guess > rand_int) {
                judge_res = 1;
                printf("greater!\n");
            } else if(guess < rand_int) {
                judge_res = -1;
                printf("lower!\n");
            }
            write(fd_arr1[1], &judge_res, 1);
        }
        close(fd_arr1[1]);
        close(fd_arr2[0]);
        exit(0);
    } else if (pid > 0) {
        // parent process
        int seed = time(NULL) + 10;
        srand(seed);
        close(fd_arr1[1]);
        close(fd_arr2[0]);
        char low = 1, high = 100;
        char pguess;
        char pjudge_res = -1;

        pguess = (char)guess_int((int)low, (int)high);
        write(fd_arr2[1], &pguess, 1);
        while(pjudge_res != 0) {
            read(fd_arr1[0], &pjudge_res, 1);
            if(pjudge_res > 0) {
                high = pguess - 1;
            } else if(pjudge_res < 0) {
                low = pguess + 1;

            }
            pguess = (char)guess_int((int)low, (int)high);
            printf("guess: %d", pguess);
            write(fd_arr2[1], &pguess, 1);
        }
        close(fd_arr1[1]);
        close(fd_arr2[0]);
        exit(0);
    } else {
        exit(1);
    }
}

int guess_int(int a, int b) {
    return rand()%(b-a) + a;
}
