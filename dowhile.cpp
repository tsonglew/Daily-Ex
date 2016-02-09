// dowhile.cpp -- exit-condition loop
#include <iostream>
int main()
{
    using namespace std;
    int n;

    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favourite numbers\n";
    do
    {
        cin >> n;
    } while (n != 7);
    cout << "Yes, 7 is my favourite.\n";
    return 0;
}