#include <iostream>
#include "PointList.h"
using namespace std;

Point initPoint(float x, float y)
{
    struct Point newPoint;
    newPoint.x = x;
    newPoint.y = y;
    return newPoint;
}

void initPointList(PointList &L)
{
    L.size = 0;
    L.cursor = -1;
}

void InitTestPointList(PointList &L)
{
    struct Point vertex;
    int i, N;

    initPointList(L);
    cout << "Enter the number of point of TestPointList: " << endl;

    cin >> N;
    while(N<=0 || N>=maxListSize)
    {
        cout << "Error! input again! " << endl;
        cin >> N;
    }

    cout << "Input each point !" << endl;
    for (i=0;i<N;i++)
    {
        cin >> vertex.x >> vertex.y;
        appendPoint(L, vertex);
    }
}

void appendPoint(PointList &L, Point newPoint)
{
    if(L.size < maxListSize)
    {
        L.size += 1;
        L.points[L.size-1] = newPoint;
        L.cursor = L.size-1;
    }
}

void clear(PointList &L)
{
    L.size = 0;
    L.cursor = -1;
}

bool isEmpty(PointList L)
{
    if(L.size==0) return true;
    else return false;
}

bool isFull(PointList L)
{
    if(L.size>=maxListSize) return true;
    else return false;
}

void gotoBeginning(PointList &L)
{
    L.cursor = 0;
}

void gotoEnd(PointList &L)
{
    L.cursor = L.size - 1;
}

bool gotoNext(PointList &L)
{
    if (L.cursor < L.size-1)
    {
        L.cursor += 1;
        return true;
    }
    else return false;
}

bool gotoPrior(PointList &L)
{
	if ( L.cursor>0 ) {
		L.cursor = L.cursor-1;
		return true;
	}
	else return false;
}

struct Point getCursor(PointList L)
{
    struct Point p;
    p.x = 0;
    p.y = 0;
    if(isEmpty(L))
    {
        return p;
    }
    else return L.points[L.cursor];
}

void testTranslation(PointList &L)
{
    struct PointList otherList;
    InitTestPointList(L);
    InitTestPointList(otherList);
    if(isTranslation(L, otherList))
    {
        cout << "Yes! They are not Translation!" << endl;
    }
    else
    {
        cout << "No! They are not Translation!" << endl;
    }
}

bool isTranslation(PointList &List, PointList &otherList )
{
	struct Point vertex1, vertex2, delta;

	if(isEmpty(List) || isEmpty(otherList)) return false;
	if(List.size != otherList.size) return false;

	gotoBeginning(List);
	gotoBeginning(otherList);
	vertex1 = getCursor(List);
	vertex2 = getCursor(otherList);
	delta.x = vertex1.x-vertex2.x;
	delta.y = vertex1.y-vertex2.y;
	do {
		vertex1 = getCursor(List);
		vertex2 = getCursor(otherList);
		if((vertex1.x!=vertex2.x+delta.x) || (vertex1.y!=vertex2.y+delta.y)) return false;
	} while (gotoNext(List) && gotoNext(otherList));

	return true;
}

void insertAtBeginning(PointList &L, Point newPoint)
{
    int i;
    if(isFull(L)) return;
    for(i=L.size-1;i>=0;i--)
    {
        L.points[i+1] = L.points[i];
    }
    L.points[0].x = newPoint.x;
    L.points[0].y = newPoint.y;
    L.cursor = 0;
    L.size = L.size+1;
}
