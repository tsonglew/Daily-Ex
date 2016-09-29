#define maxListSize 10

struct Point {
	float x;
	float y;
};

Point initPoint(float x, float y);

struct PointList {
	int size;
	int cursor;
	struct Point points[maxListSize];
};

void InitTestPointList(PointList &L);
void initPointList(PointList &L);

void appendPoint(PointList &L, Point newPoint);
void clear(PointList &L);

bool isEmpty(PointList L);
bool isFull(PointList L);

void gotoBeginning(PointList &L);
void gotoEnd(PointList &L);

bool gotoNext(PointList &L);
bool gotoPrior(PointList &L);

Point getCursor(PointList L);

void showStructure(PointList L);

void testTranslation(PointList &L);
bool isTranslation(PointList &List, PointList &otherList);
void insertAtBeginning(Point newPoint);
