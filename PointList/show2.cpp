void showStructure(PointList L)
{
    if(isEmpty(L))
    {
        cout << "Empty List" << endl;
    }

    else
    {
        for(int i=0; i<L.size; i++)
        {

            cout << "x: " << L.points[i].x << " y: " << L.points[i].y << endl;
        }
    }
}
