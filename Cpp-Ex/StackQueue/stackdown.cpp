#include <iostream>
using namespace std;

typedef double ElemType;

struct Stack {
    int maxSize;
    int top;
    ElemType *dataItems;
};

void InitStack(struct Stack &S, int maxNumber);
void DestroyStack(struct Stack &S);
void Push(struct Stack &S, ElemType newDataItem);
ElemType Pop(struct Stack &S);
void clear(struct Stack &S);
bool isEmpty(struct Stack S);
bool isFull(struct Stack S);
void showStructure(struct Stack S);


int main()
{
    struct Stack S;
    InitStack(S, 100);

    char UserIn;
    while(UserIn!='#')
    {
        switch(UserIn) {
            case '+':
                {
                double operand1 = Pop(S);
                double operand2 = Pop(S);
                double tmp = operand1 + operand2;
                Push(S, tmp);
                break;
                }
            case '-':
                {
                double operand1 = Pop(S);
                double operand2 = Pop(S);
                double tmp = operand2 - operand1;
                Push(S, tmp);
                break;
                }
            case '/':
                {
                double operand1 = Pop(S);
                double operand2 = Pop(S);
                double tmp = operand2 / operand1;
                Push(S, tmp);
                break;
                }
            case '*':
                {
                double operand1 = Pop(S);
                double operand2 = Pop(S);
                double tmp = operand1 * operand2;
                Push(S, tmp);
                break;
                }
            default:
                if(UserIn<58&&UserIn>47)
                {
                    Push(S, double(UserIn-48));
                }
                break;
        }
        cin >> UserIn;
    }
    cout << Pop(S) << endl;
    return 0;
}


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
        *(S.dataItems+(S.maxSize-S.top)*sizeof(ElemType)) = newDataItem;
    }
    else cout << "Stack is Full!" << endl;
}

ElemType Pop(struct Stack &S)
{
    if(S.top!=0)
    {
        ElemType tmp = *(S.dataItems+(S.maxSize-S.top)*sizeof(ElemType));
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
        cout << *(S.dataItems+(S.maxSize-count)*sizeof(ElemType)) << " ";
        count--;
    }
    cout << endl;
}
