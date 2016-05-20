#include <stdio.h>

struct queue
{
    int data[100];
    int head;
    int tail;
};

int main()
{
    int i = 1;
    struct queue q;
    q.head = 1;
    q.tail = 1;

    for (i=1;i<10;i++)
    {
        scanf("%1d", &q.data[i]);
        q.tail++;
    }

    while(q.head<q.tail)
    {
        printf("%d", q.data[q.head]);
        q.head++;
        q.data[q.tail] = q.data[q.head];
        q.head++;
        q.tail++;
    }
    getchar();getchar();
    return 0;
}