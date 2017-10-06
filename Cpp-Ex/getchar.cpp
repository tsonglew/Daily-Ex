#include <iostream>
#include <sstream>

using namespace std;

void getbyline();
void getaline();

int main() {
//    getaline();
    getbyline();
    return 0;
}

void getaline() {
    long long a, b;
    while(cin >> a >> b) {
        cout << a << ":" << b << endl;
    }
}

void getbyline() {
    cout << "now get by line" << endl;
    string line;
    while(getline(cin, line)) {
        int sum = 0, x;
        stringstream ss(line);
        while(ss >> x) {
            cout << x << ":" << endl;
        }
    }
}
