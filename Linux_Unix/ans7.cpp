#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
    string name;
    string sno;
    int grade;
public:
    Student(string n, string s, int g) {
        this->name = n;
        this->sno = s;
        this->grade = g;
    }
    string toString() {
        return this->name+"\t"+this->sno+"\t"+to_string(this->grade);
    }
    ~Student() {}
};

int main() {
    fstream fout, fin;
    fout.open("Record.dat", ios::out|ios::binary);
    Student* s1 = new Student("student1", "111", 90);
    Student* s2 = new Student("student2", "222", 10);
    fout << s1->toString() << endl;
    fout << s2->toString() << endl;
    fout.close();
    fin.open("Record.dat", ios::in|ios::binary);
    string line;
    while(getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
    return 0;
}
