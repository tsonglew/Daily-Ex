#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> container) {
    cout << "size: " << container.size() << endl;
    cout << "capacity: " << container.capacity() << endl;
    cout << "max_size: " << container.max_size() << endl;
}

void display(vector<int> container) {
    for(int count=0; count<container.size(); count++) {
        cout << container[count] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> container;
    for(int i=0; i<10; i++)
        container.push_back(i);
    display(container);
    for(vector<int>::iterator it = container.begin(); it!=container.end(); ++it) {
        *it += 10;
    }
    display(container);
    return 0;
}
