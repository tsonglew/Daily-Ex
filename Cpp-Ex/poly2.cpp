#include <iostream>
using namespace std;

class A {
    public:
        virtual void funcl() {cout << "A1";}
        void func2() {cout << "A2";}
};

class B: public A {
    void func1() {cout << "B1";}
    void func2() {cout << "B2";}
};

int main() {
    A *p = new B;
    p->funcl();
    p->func2();
    return 0;
}
