#include <stdio.h>

int main()
{
    int square[9][9]={};
    {
        int i, j=4, k, l, key;

        square[0][4]=1;

        for(key=2;key<=81;key++)
        {
            k=(i)? (i-1):8;
            l=(j)? (j-1):8;
            if(square[k][l])
                i=(i+1)%9;
            else
            {
                i=k;j=l;
            }
            square[i][j]=key;
        }

        for(i=0;i<9;i++)
        {
            for (j = 0; j < 9; j++)
                printf("%4d", square[i][j]);
            printf("\n");
        }
    }
}