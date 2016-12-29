#include <iostream>
using namespace std;

class counter{
    private:
        unsigned value;
    public:
        counter() {value=0;}
        counter(unsigned int a){value=a;}
        counter operator++();
        counter operator++(int);
        void display();
};

counter counter::operator++() {
    return counter(++value);
}

counter counter::operator++(int) {
    return counter(value++);
}


void counter::display() {
    cout << "Total is " << value << endl;
}

int main() {
    counter i(0), n(10);
    i = ++n;
    i.display();
    n.display();
    i = n++;
    i.display();
    n.display();
    return 0;
}
