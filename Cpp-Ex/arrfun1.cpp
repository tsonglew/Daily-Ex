// arrfun1.cpp -- functions with an array argument
#include <iostream>
const int Arsize = 8;
int sum_arr(int arr[], int n);
int main()
{
    using namespace std;
    int cookies[Arsize] = {1, 2, 4, 8, 16, 32, 64, 128};
    int sum = sum_arr(cookies, Arsize);
    cout << "Total cookies eaten: " << sum << "\n";
    return 0;
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}