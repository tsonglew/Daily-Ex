// Sum without Arithmetic
#include <iostream>

using namespace std;
int Add(int num1, int num2);

int main(){
    int sum1;
    int in1, in2;

    cout << "Input the first num: ";
    cin >> in1;
    cout << "Input the second num: ";
    cin >> in2;

    cout << "Hello World!" << endl;
    sum1 = Add(in1, in2);
    cout << "Sum: " << sum1 << endl;
    return 0;
}

int Add(int num1, int num2){
    if(num2==0){
        return num1;
    }

    int pa1 = num1^num2;
    int pa2 = (num1&num2)<<1;
    return Add(pa1, pa2);
}
