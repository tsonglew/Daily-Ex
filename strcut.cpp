#include <stdio.h>
#include <string.h>
char *substr(char *s, int startloc, int len);

int main()
{
    char a[100];
    printf("Input a string: ");
    gets(a);
    printf("%s", substr(a, 2, 2));

}

char *substr(char *s, int startloc, int len)
{
    int i;
    static char sstr[100];

    for (i=0;i<startloc;i++)
        s++;

    i = 0;
    while (i<len)
    {
        sstr[i]=*s;
        i++;
        s++;
    }
    sstr[i] = '\0';
    return sstr;
}
