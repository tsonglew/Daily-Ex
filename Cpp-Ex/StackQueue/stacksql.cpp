#include <iostream>
#include "stacksql.h"
using namespace std;

void InitStack(struct Stack &S, int maxNumber)
{
    S.top = 0;
    S.maxSize = maxNumber;
    S.dataItems = new ElemType[maxNumber];
}

void DestroyStack(struct Stack &S)
{
    S.maxSize = 0;
    S.top = 0;
    delete [] S.dataItems;
}

void Push(struct Stack &S, ElemType newDataItem)
{
    if(S.top!=S.maxSize)
    {
        S.top++;
        *(S.dataItems+S.top*sizeof(ElemType)) = newDataItem;
    }
    else cout << "Stack is Full!" << endl;
}

ElemType Pop(struct Stack &S)
{
    if(S.top!=0)
    {
        ElemType tmp = *(S.dataItems+S.top*sizeof(ElemType));
        S.top--;
        return tmp;
    }
    else cout << "Stack is Empty!" << endl; return 0;
}

void clear(struct Stack &S)
{
    S.top = 0;
}

bool isEmpty(struct Stack S)
{
    return (S.top==0);
}

bool isFull(struct Stack S)
{
    return (S.top==S.maxSize);
}

void showStructure(struct Stack S)
{
    int count = S.top;
    while(count)
    {
        cout << *(S.dataItems+count*sizeof(ElemType)) << " ";
        count--;
    }
    cout << endl;
}
