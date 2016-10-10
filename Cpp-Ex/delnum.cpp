#include <stdio.h>
#include <string.h>

void func(char *s);

int main()
{
    char str[100];

    printf("Input a string: ");
    gets(str);
    printf("Before: %s\n", str);
    func(str);
    printf("After: %s\n", str);
    getchar();getchar();
    return 0;
}

void func(char *s)
{
    char *pstart;

    for (pstart=s;*pstart!='\0';pstart++)
    {
        while(*pstart<='9' && *pstart>='0')
            strcpy(pstart, pstart+1);
    }
    *pstart='\0';
}
