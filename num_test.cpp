// num_test.cpp -- use numeric test in for loop
#include <iostream>
int main()
{
    using namespace std;
    cout << "Enter the starting countdown value: ";
    int limit;
    cin >> limit;
    int i;
    for(i = limit; i; i--)    // quit when i is 0
        cout << "i= " << i << endl;
    cout << "Done now that i = " << i << endl;
    return 0;
}