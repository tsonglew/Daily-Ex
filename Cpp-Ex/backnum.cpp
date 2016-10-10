#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], *pstart, *pend;
    int len;

    printf("Input a string: ");
    gets(a);

    len = (int)strlen(a);

    pstart = a;
    pend = pstart + len - 1;

    while (*pstart==*pend && pstart < pend)
    {
        pstart++;
        pend--;
    }

    if (pstart<pend)
        printf("No!");
    else
        printf("Yes!");
    getchar();getchar();
    return 0;
}
