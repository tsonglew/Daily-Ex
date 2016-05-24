#include <stdio.h>

int main()
{
    int e[10][10], book[10], dis[10], n, m, i, j, t1, t2, t3, u, v, min;
    int inf = 99999;

    printf("Input the number of the numbers of the spots and the sides: (spots,sides)");
    scanf("%d,%d", &n, &m);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i=j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
        }
    }

    for (i=1;i<=m;i++)
    {
        printf("Input two spots and the distance between them: (spot1,spot2,distance)");
        scanf("%d,%d,%d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }

    for (i=1;i<=n;i++)
        book[i] = 0;
    book[1]=1;

    for (i=1;i<=n;i++)
        dis[i] = e[1][i];

    for (i=1;i<=n;i++)
    {
        min = inf;
        for (j=1;j<=n;j++)
        {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[j] = 1;
        for (v=1;v<=n;v++)
        {
            if (dis[v]<inf)
            {
                if (dis[v]<dis[u]+e[u][v])
                    dis[v]=dis[u]+e[u][v];
            }
        }
    }

    for (i=1;i<=n;i++)
        printf("%d ", dis[i]);

    getchar();getchar();
    return 0;
}