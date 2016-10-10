#include <stdio.h>
#include <cstring>

int main()
{
    int i;
    char a[16]={'a', 'a', 'b', 'b', 'c', 'c', 'd', 'd', '\0'}, b[16];

    printf ("password in: ");
    scanf ("%s", b);

    if (strlen(a)!=strlen(b))
    {
        printf ("wrong password");
        return 0;
    }


    for (i=0;a[i]!='\0' && b[i]!='\0';)
    {
        if (a[i]==b[i])
            i++;
        else
        {
            printf ("wrong password!");
            return 0;
        }
    }

    printf ("password correct!");
    return 0;
}