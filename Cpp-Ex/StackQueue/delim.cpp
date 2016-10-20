#include "stacksql.cpp"

bool delimitersOk(string &expression);

int main()
{
    string Exp1 = "3*(a+b)";
    string Exp2 = "f[3*(a+b)]";
    string Exp3 = "(f[b)-(c+d)])/2";
    string Exp4 = "<\n>";
    string Exp5 = "a=f[b+3";
    if(delimitersOk(Exp1)) cout << "OK!" << endl;
    else cout << "NO!" << endl;
    if(delimitersOk(Exp2)) cout << "OK!" << endl;
    else cout << "NO!" << endl;
    if(delimitersOk(Exp3)) cout << "OK!" << endl;
    else cout << "NO!" << endl;
    if(delimitersOk(Exp4)) cout << "OK!" << endl;
    else cout << "NO!" << endl;
    if(delimitersOk(Exp5)) cout << "OK!" << endl;
    else cout << "NO!" << endl;

    return 0;
}

bool delimitersOk(string &expression)
{
    struct Stack S;
    InitStack(S,100);


    int count = 0;
    char k = expression[count];
    while(k!='\0')
    {
        count++;
        k=expression[count];
    }
    int lens = count;
    count = 0;

    while(count < lens)
    {
        char exp = expression[count];
        if(exp=='('||exp=='['||exp=='<') Push(S, exp);
        else if(exp==')')
        {
            char check = Pop(S);
            if(check!='(') return false;
        }
        else if(exp=='>')
        {
            char check = Pop(S);
            if(check!='<') return false;
        }
        else if(exp==']')
        {
            char check = Pop(S);
            if(check!='[') return false;
        }
        count++;
    }
    if(isEmpty(S)) return true;
    else return false;
}
