#include <stdio.h>
#define COL 2
#define ROW 2

int main()
{
    int pic1[COL][ROW][3], pic2[COL][ROW][3], pic3[COL][ROW][3];
    int i,j,k,m;
    int s1=0, s2=0;

    printf("输入第一张图片的(r,g,b):");
    for (i=0;i<COL;i++)
        for (j=0;j<ROW;j++)
            for (k=0;k<3;k++)
                scanf("%d", &pic1[i][j][k]);

    printf("输入第二张图片的(r,g,b):");
    for (i=0;i<COL;i++)
        for (j=0;j<ROW;j++)
            for (k=0;k<3;k++)
                scanf("%d", &pic2[i][j][k]);

    printf("输入第三张图片的(r,g,b):");
    for (i=0;i<COL;i++)
        for (j=0;j<ROW;j++)
            for (k=0;k<3;k++)
                scanf("%d", &pic3[i][j][k]);

    printf("Calculating s1...");
    for (i=0;i<COL;i++)
        for (j=0;j<ROW;j++)
            for (k=0;k<3;k++)
            {
                m = (pic1[i][j][k] - pic2[i][j][k]);
                s1 += (m * m);
            }
    s1/=COL*ROW*3;
    printf("s1计算完成, s1=%d!\n", s1);

    printf("Calculating s2...");
    for (i=0;i<COL;i++)
        for (j=0;j<ROW;j++)
            for (k=0;k<3;k++)
            {
                m = (pic1[i][j][k] - pic3[i][j][k]);
                s2 += (m*m);
            }
    s2/=COL*ROW*3;
    printf("s2计算完成!, s2=%d\n", s2);

    if (s1>s2)
        printf("图一与图三更相近!\n");
    else if (s1==s2)
        printf("图一与图二图三相似度相同!\n");
    else
        printf("图一与图二更相近!\n");
}