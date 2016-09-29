#include <iostream>
#include "PointList.cpp"
using namespace std;

void TestPointList(void)
{
    struct PointList polygon;
    struct Point vertex;
    initPointList(polygon);

    cout << "Enter the polygons vertices(end with eof):" << endl;
    float x, y;

    while(cin >> vertex.x >> vertex.y && !isFull(polygon))
    {
        appendPoint(polygon, vertex);
    }

    if(!isEmpty(polygon))
    {
        gotoBeginning(polygon);
        do{
            vertex = getCursor(polygon);
            cout << "(" << vertex.x << "," << vertex.y << ")" << endl;
        } while(gotoNext(polygon));
    }
}


int main()
{
    TestPointList();
    return 0;
}
