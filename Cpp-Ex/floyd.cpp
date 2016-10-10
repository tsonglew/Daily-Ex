#include <stdio.h>

int main()
{
    int e[4][4], i, j, k, in1, in2, in3;
    int inf = 9999;

    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
            if (i==j) e[i][j]=0; else e[i][j]=inf;

    while (1)
    {
        scanf("%d,%d,%d",&in1,&in2,&in3);
        if (in1==-1)
            break;
        else
            e[in1][in2]=in3;
    }

    for (k=0;k<4;k++)
        for (i=0;i<4;i++)
            for (j=0;j<4;j++)
                if (e[i][j]>e[i][k]+e[k][j])
                    e[i][j]=e[i][k]+e[k][j];

    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
            printf("%d ", e[i][j]);
        printf("\t");
    }
    getchar();getchar();
    return 0;
}
