#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int arc, char *argv[]) {
    DIR *dirp;
    struct dirent *direntp;
    struct stat info;
    int filecount = 0;
    int dircount = 0;
    stat(argv[1], &info);

    if((dirp = opendir(argv[1])) == NULL) {
        fprintf(stderr, "error message: %s\n", strerror(errno));
        exit(1);
    }

    strcat(argv[1], "/");
    printf("Directory List:\n");
    while((direntp = readdir(dirp)) != NULL) {
        char dir[100];
        strcpy(dir, argv[1]);
        strcat(dir, direntp->d_name);
        stat(dir, &info);
        if(S_ISDIR(info.st_mode)) {
            printf("%s\n", direntp->d_name);
            dircount++;
        } else {
            filecount++;
        }
    }
    closedir(dirp);
    printf("Total %d files, %d directories\n", filecount, dircount);
    exit(0);
}
