#include <stdio.h>

void printch(int i) {
    switch (i) {
        case 0: printf("ling"); break;
        case 1: printf("yi"); break;
        case 2: printf("er"); break;
        case 3: printf("san"); break;
        case 4: printf("si"); break;
        case 5: printf("wu"); break;
        case 6: printf("liu"); break;
        case 7: printf("qi"); break;
        case 8: printf("ba"); break;
        case 9: printf("jiu"); break;
    }
}

int main() {
    int tem[100];
    char user_input;
    int each, sum=0;
    scanf("%c", &user_input);

    while(user_input) {
        each = (int)user_input-48;
        if(each<0||each>9) break;
        sum += each;
        scanf("%c", &user_input);
    }

    int i = 0;
    while(sum) {
        tem[i] = sum%10;
        sum/=10;
        i++;
    }
    i--;
    while(i!=-1) {
        printch(tem[i]);
        if(i!=0) printf(" ");
        i--;
    }

    return 0;
}
