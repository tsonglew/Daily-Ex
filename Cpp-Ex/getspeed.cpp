#include <iostream>
using namespace std;

class vehicle {
    protected:
        int size;
        int speed;
    public:
        void setSpeed(int s){speed=s;}
        virtual int getSpeedLevel(){return speed/10;}
};

class car: public vehicle {
    public:
        int getSpeedLevel() {return speed/5;}
};

class truck: public vehicle {
    public:
        int getSpeedLevel() {return speed/15;}
};

int maxSpeedLevel(vehicle v1, vehicle v2) {
    cout << v1.getSpeedLevel() << ":" << v2.getSpeedLevel() << endl;
    if(v1.getSpeedLevel()>v2.getSpeedLevel()) return 1;
    else return 2;
}

int main() {
    truck t;
    car c;
    t.setSpeed(130);
    c.setSpeed(60);
    cout << maxSpeedLevel(t, c) << endl;
    return 0;
}
