#include <iostream>
#include "PointList.cpp"
using namespace std;

int main()
{
    struct Point newPoint;
    struct PointList polygon;
    initPointList(polygon);

    char user_input;
    while(cin >> user_input)
    {
        if (user_input=='+')
        {
            float x, y;
            cin >> x;
            cin >> y;
            newPoint = initPoint(x, y);
            appendPoint(polygon, newPoint);
        }

        else if(user_input=='@')
        {
            newPoint = getCursor(polygon);
            cout << "(" << newPoint.x << ":" << newPoint.y << ")" << endl;
        }

        else if(user_input=='P')
        {
            if(!gotoPrior(polygon))
            {
                cout << "No Prior Point!" << endl;
            }
        }

        else if(user_input=='N')
        {
            if(!gotoNext(polygon))
            {
                cout << "No Next Point!" << endl;
            }
        }

        else if(user_input=='<')
        {
            gotoBeginning(polygon);
        }

        else if(user_input=='>')
        {
            gotoEnd(polygon);
        }

        else if(user_input=='E')
        {
            if(isEmpty(polygon))
            {
                cout << "The PointList is Empty!" << endl;
            }
            else
            {
                cout << "The PointList is not Empty!" << endl;
            }
        }

        else if(user_input=='F')
        {
            if(isFull(polygon))
            {
                cout << "The PointList is Full!" << endl;
            }
            else
            {
                cout << "The PointList is not Full!" << endl;
            }
        }

        else if(user_input=='C')
        {
            clear(polygon);
        }

        else if(user_input=='Q')
        {
            return 0;
        }

        else if(user_input=='T')
        {
            testTranslation(polygon);
        }

        else if(user_input=='#')
        {
            float x, y;
            cin >> x;
            cin >> y;
            newPoint = initPoint(x, y);
            insertAtBeginning(polygon, newPoint);
        }
    }
    return 0;
}
