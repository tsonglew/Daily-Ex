#include "stacklnk.cpp"

int main()
{
    struct Stack S;
    InitStack(S, 5);

    char UserIn;
    cout << "Your Choice: " << endl;
    cin >> UserIn;
    while(UserIn!='Q')
    {
        switch (UserIn) {
            case '+':
                {
                    char newdata;
                    cin >> newdata;
                    Push(S, newdata);
                    break;
                }
            case '-': cout <<  Pop(S) << endl; break;
            case 'E':
                {
                    if (isEmpty(S)) cout << "Empty!" << endl;
                    else cout << "Not Empty!" << endl;
                    break;
                }
            case 'F':
                {
                    if (isFull(S)) cout << "Full!" << endl;
                    else cout << "Not Full!" << endl;
                    break;
                }
            case 'C': clear(S); break;
            case 'S': showStructure(S); break;
            default: cout << "Illegal Input!" << endl; break;
        }
        cin >> UserIn;
    }
    DestroyStack(S);
    return 0;
}
