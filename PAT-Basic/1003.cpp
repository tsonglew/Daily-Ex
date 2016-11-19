#include <stdio.h>
#include <stdlib.h>

int main() {
    char user_input;
    char chars[100];
    int count;
    int acount;
    int allnum = 0;
    int flag;
    scanf("%d", &allnum);
    allnum--;
    scanf("%c", &user_input);

start:
    count = 0;
    acount = 0;
    flag = 0;

    scanf("%c", &user_input);
    while(user_input!='\n') {
        chars[count++] = user_input;
        scanf("%c", &user_input);
    }
    if (count<3) {
        printf("NO\n");
        goto end;
    }

    count--;

    while(count>-1) {

        if(chars[count]!='P'&&chars[count]!='A'&&chars[count]!='T') {
            printf("NO\n");
            goto end;
        }

        if(flag==1) {

            if(chars[count] == 'A') {
                acount += 1;
                if (acount>2) {
                    printf("NO\n");
                    goto end;
                }
            }

            else if (chars[count] == 'T') {
                printf("NO\n");
                goto end;
            }

            else {
                if(acount == 0) {
                    printf("NO\n");
                    goto end;
                } else {
                    flag = 2;
                }
            }
        }

        else if (flag == 0){
            if(chars[count]=='P') {
                printf("NO\n");
                goto end;
            }
            else if(chars[count]=='T') {
                flag = 1;
            }
        }

        else if (flag == 2){
            if(chars[count]!='A') {
                printf("NO\n");
                goto end;
            }
        }

        count--;
    }

    printf("YES\n");

end:
    count = 0;
    if(allnum) {
        allnum--;
        goto start;
    }
    return 0;
}
