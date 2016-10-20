typedef char ElemType;

struct StackNode {
    ElemType dataItem;
    struct StackNode *next;
};

struct Stack {
    int max;
    int Size;
    struct StackNode  *top;
};

void InitStack(struct Stack &S, int maxNumber);
void DestroyStack(struct Stack &S);
void Push(struct Stack &S, ElemType newDataItem);
ElemType Pop(struct Stack &S);
void clear(struct Stack &S);
bool isEmpty(struct Stack S);
bool isFull(struct Stack S);
void showStructure(struct Stack S);
