#include <iostream>
using namespace std;

template <class T, int size>
void func(T a) {
    for(T i=0; i<a; i+=size) {
        cout << "hello" << endl;
    }
}

int main() {
    func<int, 2>(5);
    return 0;
}
