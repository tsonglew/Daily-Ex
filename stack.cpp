#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], s[100];
    int i, mid, len, top, next;

    printf("Input an array: ");
    gets(a);

    len = (int) strlen(a);
    mid = len/2 - 1;
    for (i=0; i<=mid; i++)
    {
        s[++top] = a[i];
    }

    if (len/2 == 0)
        next = mid + 1;
    else
        next = mid + 2;

    for (i=next; i<=len-1; i++)
    {
        if (s[top--] != a[i])
            break;
    }

    if (top == 0)
        printf ("Yes!");
    else
        printf ("No!");
    getchar();getchar();
    return 0;
}
