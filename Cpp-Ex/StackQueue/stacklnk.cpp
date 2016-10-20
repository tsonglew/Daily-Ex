#include <iostream>
#include "stacklnk.h"
using namespace std;

void InitStack(struct Stack &S, int maxNumber)
{
    S.max = maxNumber;
    S.Size = 0;
    S.top = NULL;
}

void DestroyStack(struct Stack &S)
{
    struct StackNode *p;
    p = S.top;
    while(S.top!=NULL)
    {
        S.top = p->next;
        delete p;
        p = S.top;
    }
    S.Size = 0;
}

void Push(struct Stack &S, ElemType newDataItem)
{
    if(S.Size<S.max)
    {
        struct StackNode *newStack = new struct StackNode;
        newStack->dataItem = newDataItem;
        newStack->next = S.top;
        S.top = newStack;
        S.Size++;
    }
    else cout << "Stack is Full!" << endl;
}

ElemType Pop(struct Stack &S)
{
    if(S.Size>0)
    {
        ElemType tmp = S.top->dataItem;
        struct StackNode *p;
        p = S.top;
        S.top = p->next;
        delete p;
        S.Size--;
        return tmp;
    }
    cout << "Stack is Empty!" << endl;
    return 0;
}

void clear(struct Stack &S)
{
    struct StackNode *p;
    p = S.top;
    while(S.top!=NULL)
    {
        S.top = p->next;
        delete p;
        p = S.top;
    }
    S.Size = 0;
}

bool isEmpty(struct Stack S)
{
    return (S.Size==0);
}

bool isFull(struct Stack S)
{
    return (S.Size==S.max);
}

void showStructure(struct Stack S)
{
    struct StackNode *p;
    p = S.top;
    while(p!=NULL)
    {
        cout << p->dataItem << " " ;
        p = p->next;
    }
    cout << endl;
}
