#include <stdio.h>
int h[101];  // init the heap
int n;  // size of the heap

// swap two numbers according to the index
void swap(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
}

void shiftdown(int i)
{
    int t, flag=0;  // flag record whether the number needs to be 
    while (i*2<=n && flag==0)
    {
        if (h[i]>h[2*i])
            t=i*2;
        else
            t=i;

        if (i*2+1<=n)
        {
            if (h[t]>h[i*2+1])
                t=i*2+1;
        }

        if (t!=i)
        {
            swap(i, t);
            i=t;
        }
        else
            flag=1;
    }
}

void create()
{
    int i;
    for (i=n/2;i>=1;i--)
    {
        shiftdown(i);
    }
}

int deletemax()
{
    int t;
    t=h[1];
    h[1]=h[n];  // replace the first number with the last one
    n--;  // decline the size of the heap
    shiftdown(1);  // move the first number to the optimium place
    return t;  // display the number
}

int main()
{
    int i, num;
    printf("Input the size of the heap: ");
    scanf("%d", &num);

    for (i=1;i<=num;i++)
        scanf("%d", &h[i]);
    n=num;

    create();  // sort and initialize the heap

    // display the heap in squence
    for (i=1;i<=num;i++)
        printf("%d ", deletemax());

    getchar();getchar();
    return 0;
}