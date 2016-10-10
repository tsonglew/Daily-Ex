#include <iostream>

int main()
{
    using namespace std;

    long pwd;
    cout << '\a';
    cout << "Enter your password:_________ " << "\b\b\b\b\b\b\b\b\b\b";
    cin >> pwd;
    cout << "You entered " << pwd << "." << endl;
    return 0;
}
