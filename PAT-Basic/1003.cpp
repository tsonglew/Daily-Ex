#include <stdio.h>

int main() {
    char user_input; // Get input character in a single string
    char chars[100]; // Store the characters(in a single string) temporarily
    int count; // Count the number of user_inputs' characters
    int acount; // Count 'A' shown up in the middle of a 'P' and 'T'
    int allnum = 0; // Count the strings to check
    int flag; // A flag to tell whether in the middle of 'P' and 'T'  or not

    // get the total number of the strings to check
    scanf("%d", &allnum);
    allnum--;

    // get the first character should be the '\n' after allnum
    scanf("%c", &user_input);

start:

    // Initialization
    count = 0;
    acount = 0;
    flag = 0;

    // store user_inputs to chars[]
    scanf("%c", &user_input);
    while(user_input!='\n') {
        chars[count++] = user_input;
        scanf("%c", &user_input);
    }

    // if the counts of the string is less than 3, it cannot contains 'PAT'(the
    // shortest legal string)
    if (count--<3) {
        printf("NO\n");
        goto end;
    }

    // check each character of a string
    while(count>-1) {
        // only 'P' 'A' 'T' is legal
        if(chars[count]!='P'&&chars[count]!='A'&&chars[count]!='T') {
            printf("NO\n");
            goto end;
        }

        // flag==1, checking in the middle of 'P' and 'T'
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

        // flag==0
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

    // passed all the tests
    printf("YES\n");

end:
    count = 0;

    // with a subsequent string to check
    if(allnum) {
        allnum--;
        goto start;
    }

    // finished
    return 0;
}
