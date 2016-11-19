#include <iostream>
using namespace std;

int main() {
    int count = 2;
    char chars[] = {'P', 'A', 'T'};

    int acount = 0;
    bool flag = false;

    while(count>-1) {
        cout << "checking on : " << chars[count] << endl;
        if(chars[count]!='P'&&chars[count]!='A'&&chars[count]!='T') {
            printf("NO1\n");
            goto end;
        }
        cout << chars[count] << " is legal " << endl;
        cout << "now flag : " << flag << endl;
        cout << "acount : " << acount << endl;

        if(flag) {

            if(chars[count] == 'A') {
                acount += 1;
            }

            else if (chars[count] == 'T') {
                printf("NO2\n");
                goto end;
            }

            else {
                if(acount == 0) {
                    printf("NO3\n");
                    goto end;
                } else {
                    flag = false;
                }
            }
        }

        else {
            if(chars[count]=='P') {
                printf("NO4\n");
                goto end;
            }
            else if(chars[count]=='T') {
                flag = true;
            }
        }
        count--;
    }
end:
    return 0;
}
