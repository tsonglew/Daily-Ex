#include <iostream>
using namespace std;

class A {
    public:
        A() {cout << "start of A" << endl;}
        // virtual ~A() { cout << "end of A" << endl; }
        ~A() { cout << "end of A" << endl; }
};

class B: public A {
    public:
        B() { cout << "Creating B" << endl; }
        ~B() { cout << "end of B" << endl; }
};

int main() {
    A *pa = new B;
    delete pa;
    return 0;
}
