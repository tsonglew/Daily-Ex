// ourfunc.cpp -- defining your own function
#include <iostream>
void simon(int);    // function prototype for simon()
using namespace std;

int main()
{
    int count;
    simon(3);    // call the simon() function
    cout << "Pick an integer: ";
    cin >> count;
    simon(count);    // call it again
    cout << "Done!";
    return 0;
}

void simon(int n)
{
    cout << "Simon says touch your toes " << n << " times." << endl;
}
