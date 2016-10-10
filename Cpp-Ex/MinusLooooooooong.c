#include <stdio.h>
#include <conio.h>
#include <string.h>

#define N  20

void beep ( );
void GetNumberStr (char s[ ]);
void MinusNumberStr (char a[ ], char b[ ], char c[ ]);
char MinusChar (char ch1, char ch2);
void LeftTrim (char str[ ]);

int tag = 0;
void main ( )
{
    char a[N+1] = {0}, b[N+1] = {0}, c[N+2];

    printf ("a = ");
    while (strlen (a) == 0)
        GetNumberStr (a);
    printf ("\nb = ");
    while (strlen (b) == 0)
        GetNumberStr (b);

    AddNumberStr (a, b, c);
    printf ("\na + b = %s \n", c);
}

void GetNumberStr (char s[ ])
{
    int i = 0;
    char ch;
    while ( 1 )
    {
        ch = getch ( );
        if (ch == '\r')
            break;
        if (ch == '\b')
        {
            if (i > 0)
            {
                printf ("%c %c", ch, ch);
                i--;
            }
            else
                beep ( );
            continue;
        }
        if (ch < '0' || ch > '9')
        {
            beep ( );
            continue;
        }
        if (i < N)
        {
            printf ("%c", ch);
            s[i++] = ch;
        }
        else
            beep ( );
    }
    s[i] = '\0';
}

void beep ( )
{
    printf("\07");
}

void MinusNumberStr (char a[ ], char b[ ], char c[ ])
{
    int i=0, j=0, k=0;
    memset (c, ' ', N+2);
    k = N;

    while (i < (strlen(a) - 1) && j < (strlen(b) - 1))
        c[k++] = MinusChar (a[i++], b[j++]);
    while (i >= 0)
        c[k++] = MinusChar (a[i++], '0');
    while (j >= 0)
        c[k++] = MinusChar (b[j++], '0');
    if (tag == 1)
        c[k] = '1';
    c[N+1] = '\0';
    LeftTrim (c);
}

char MinusChar (char ch1, char ch2)
{
    char ch;
    ch = ((ch1-0x30) - (ch2-0x30)) - tag;
    if (ch < 0)
    {
        tag = 1;
        return (10 - ch + 0x30);
    }
    else
    {
        tag = 0;
        return (ch + 0x30);
    }
}

void LeftTrim(char str[ ])
{
    int i;
    for(i = 0; str[i] == ' '; i++) ;
    strcpy (str, str+i);
}