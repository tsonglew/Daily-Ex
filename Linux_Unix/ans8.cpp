// 编写一C/C++程序，将一个C/C++语言源程序每行加上一个行号。

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    int count = 1;
    ofstream of;
    ifstream inf;
    inf.open("test.sh");
    of.open("target.sh");
    string line;
    while(getline(inf, line)) {
        of << count << ". " << line << endl;
        count ++;
    }
    inf.close();
    of.close();
    return 0;
}
