#include <iostream>
using namespace std;

int x[8] = {-1};

bool Place(int k, int n) {
    for (int i=0; i<k; i++) {
        if (x[i]==k || abs(i-k)==abs(x[i]-x[k])) {
            return true;
        }
    }
    return false;
}

void Eight_Queen(int k, int n) {
    if (k < n) {
        x[k]++;
        while(x[k] < n && Place(k, n)) {
            x[k]++;
        }
        if (x[k]<n && k==n-1) {
            for (int i=0; i<n; i++) {
                cout << x[k] << " ";
            }
            cout << endl;
            return;
        }
        if (x[k]<n && k<n-1) {
            Eight_Queen(k+1, n);
        } else {
            Eight_Queen(k-1, n);
        }
    }
}

int main() {
    int k = 0;
    Eight_Queen(k, 8);
    return 0;
}
