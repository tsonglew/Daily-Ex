#include <stdio.h>

int main() {
    int len, count, flag=0;
    char ch_in;
    char tem[100];

    scanf("%d", &len);
    printf("len in : %d", len);
    scanf("%c", &ch_in);
    printf("ch in : %c", ch_in);

    while(len) {
        count = 0;
        flag = 0;
        if (ch_in=='\n') goto end;
        while(ch_in!='\n') {
            printf("ch in : %c\n", ch_in);
            if (ch_in=='\n') break;
            if (ch_in!='P' && ch_in!='A' && ch_in!='T') {
                printf("NO1\n");
                goto end;
            }
            tem[count++] = ch_in;
            scanf("%c", &ch_in);
        }


        for(int i=0; i<count; i++) {
            printf("Checking on %c\n", tem[i]);
            if (!flag) {
                if (tem[i]=='A') continue;
                else if (tem[i]=='T') {
                    printf("NO2\n");
                    break;
                }
                else flag=1;
            }
            else {
                if (tem[i]=='T') flag=0;
                else if (tem[i]=='A') continue;
                else {
                    printf("NO3\n");
                    break;
                }
            }
            tem[i] = 'n';
        }
        printf("YES\n");
end:
        len--;
        printf("len %d\n", len);
        scanf("%c", &ch_in);
        while(ch_in!='\n') continue;
        scanf("%c", &ch_in);
    }
    return 0;
}
