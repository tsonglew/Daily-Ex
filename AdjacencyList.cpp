#include <stdio.h>

int main()
{
    int i, k;
    int u[6], v[6], w[6];
    int first[5], next[6];

    // initialize the first array
    for (i=1;i<=4;i++)
        first[i]=-1;

    // import the data of the lines
    for (i=1;i<=5;i++)
    {
        printf("Input %d: ", i);
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        printf("\n");
        next[i]=first[u[i]];
        first[u[i]]=i;
    }

    // export the data
    for (i=1;i<=4;i++)
    {
        k=first[i];
        while(k!=-1)
        {
            printf("%d %d %d\n", u[k], v[k], w[k]);
            k = next[k];
        }
    }
}
