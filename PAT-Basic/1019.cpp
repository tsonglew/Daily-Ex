#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool upsort(int i,int j) { return (i<j); }
bool downsort(int i, int j) { return (i>j); }

int main() {
    int input_num;
    int each_bit;
    int mulsmall;
    int mulbig;
    int big;
    int small;
    
    cin >> input_num;
    int check_nums = input_num;
    vector<int> check;
    while (check_nums) {
        each_bit = check_nums % 10;
        check_nums /= 10;
        check.push_back(each_bit);
    }
    if(check[0]==check[1]&&check[1]==check[2]&&check[2]==check[3]) {
        cout << input_num << " - " << input_num << " = " << "0000" << endl;
        exit(0);
    }
    
    do {
        mulbig = 1;
        mulsmall = 1000;
        big = 0;
        small = 0;
        vector<int> nums;
        
        while (input_num) {
            each_bit = input_num % 10;
            input_num /= 10;
            nums.push_back(each_bit);
        }
        
        sort(nums.begin(), nums.end(), upsort);
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            small += mulsmall * (*it);
            big += mulbig * (*it);
            mulsmall /= 10;
            mulbig *= 10;

        }
        input_num = big - small;
        cout << setw(4) << setfill('0') << big << " - " << setw(4) << setfill('0') << small << " = " << setw(4) << setfill('0') << input_num << endl;
    } while(input_num!=6174);
    
    return 0;
}
