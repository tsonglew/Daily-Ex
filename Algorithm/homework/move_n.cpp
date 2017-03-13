// 设计分治算法实现将数组A[n]中的所有元素循环左移k个位置，时间复杂性O(n)，空间复杂性O(1)
#include <iostream>
using namespace std;

void print(char A[], int len){
    int count = 0;
    while(count < len) {
        cout << A[count] << " ";
        count ++;
    }
}

class Solution{
private:
    void reverse(char A[], int begin, int len) {
        char temp;
        int head = begin;
        int tail = len - 1;
        while(head < tail) {
            temp = A[head];
            A[head] = A[tail];
            A[tail] = temp;
            head++; tail--;
        }
    }
public:
    void move_n(char A[], int len, int n) {
        reverse(A, 0, len);
        reverse(A, 0, len-n);
        reverse(A, len-n, len);
    }
};


int main() {
    Solution s;
    char A[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    s.move_n(A, 8, 3);
    print(A, 8);
    return 0;
}
