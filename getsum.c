#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int GetMaxRow(int **p, int row, int col);
int GetSum(int *p, int col);

void main()
{
	int i, j, maxrow=0;
	int **p, row, col;
	
	printf("Input row: ");
	scanf("%d", &row);
	printf("Input col: ");
	scanf("%d", &col);

	p = (int **)malloc(row*sizeof(int*));
	if(p==NULL)
		exit(0);
	for(i=0;i<row;i++)
		p[i]=(int *)malloc(col*sizeof(int));

	printf("Input the numbers: \n");
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d", p[i]+j);

	maxrow = GetMaxRow(p, row, col);
	printf("max row=%d\n", maxrow);
	
	for(i=0;i<row;i++)
		free(p[i]);
	free(p);
	getchar();getchar();
}

int GetMaxRow(int **p, int row, int col)
{
	int i, t, max;

	max = GetSum(p[0], col);
	for(i=1;i<row;i++)
	{
		t = GetSum(p[i], col);
		if(t>max)
			max=t;
	}
	return (max);
}

int GetSum(int *p, int col)
{
	int i, sum=0;

	for(i=0;i<col;i++)
		sum+=*(p+i);
	return (sum);
}
