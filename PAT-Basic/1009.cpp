#include <stdio.h>

int main() {
    char input[80][80] = {0};
    int row=0, col=0;

    scanf("%c", &input[row][col]);
    while(input[row][col]!='\n') {
        if(input[row][col]==' ') {
            if(row==0) {
                input[row][col] = '\0';
            }
            row++;
            col = 0;
        }
        else {
            col++;
        }
        scanf("%c", &input[row][col]);
    }
    input[row][col] = ' ';

    for(;row>=0;row--) {
        for(col=0;input[row][col];col++) {
            printf("%c", input[row][col]);
        }
    }
    return 0;
}
