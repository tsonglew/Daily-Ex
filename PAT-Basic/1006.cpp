#include <stdio.h>

int main() {
    int num_count = 0;
    int all_num = 0;
    char char_in;
    char all_chars[3];

    int all_ints[3];
    int int_count=2;

    int unit = 0;
    int decade = 0;
    int hundreds = 0;

    scanf("%c", &char_in);
    while(char_in!='\n') {
        all_chars[num_count] = char_in;
        num_count++;
        scanf("%c", &char_in);
    }

    num_count--;
    for(int_count=2; int_count>-1; int_count--) {
        if(num_count>-1) {
            all_ints[int_count] = int(all_chars[num_count])-48;
            num_count--;
        } else {
            all_ints[int_count] = 0;
        }
    }
    if(all_ints[0]!=0) {
        hundreds = all_ints[0];
        while(hundreds) {
            printf("B");
            hundreds--;
        }
    }
    if(all_ints[1]!=0) {
        decade = all_ints[1];
        while(decade) {
            printf("S");
            decade--;
        }
    }
    if(all_ints[2]!=0) {
        unit = 0;
        while(unit<all_ints[2]) {
            printf("%d", ++unit);
        }
    }
    return 0;
}
