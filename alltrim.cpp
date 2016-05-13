#include <stdio.h>
#include <string.h>

void alltrim(char pstr[], char str[]);

int main()
{
    char pstr1[20], str[20];
    pstr1[20] = "  Hello World~!  ";

    printf("before alltrim: %s\n", pstr1);
    alltrim(pstr1, str);
    printf("after alltrim: %s\n", str);
    return 0;
}

void alltrim(char *pstr, char str[])
{
    char *pend;

    while(*pstr == ' ')
        pstr++;

    pend = pstr+strlen(pstr)-1;
    while(*pend == ' ')
        pend--;

    while(pstr<=pend)
        *str++ = *pstr++;
    *pstr = '\0';
}
