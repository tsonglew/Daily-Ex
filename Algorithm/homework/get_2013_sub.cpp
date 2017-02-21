#include <iostream>
using namespace std;

int main() {
    int num_count = 1;
    int num = 1;
    while(num!=0){
        num = (num*10+1)%2013;
        num_count++;
    }
    cout << num_count << endl;
    return 0;
}
