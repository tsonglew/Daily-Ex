#include <stdio.h>

int main()
{
    int i,j,k,a[9][9]={0};

    a[0][4]=1;
    for(k=2;k<=81;k++)
    {
        i--;
        j++;

        if(i<0) i=8;
        else if(j>8) j=0;

        if(a[i][j]==0)
            a[i][j]=k;
        else
        {
            i=(i+2)%9;
            j=(j-1+9)%9;
            a[i][j]=k;
        }
    }

    for(i=0;i<9;i++)
    {
        printf("\t");
        for(j=0;j<9;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    return 0;
}