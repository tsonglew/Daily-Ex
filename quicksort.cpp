#include <stdio.h>
int a[10];

void quicksort(int left, int right)
{
    int i, j, t, tmp;
    if (left>right)
        return;

    i = left;
    j = right;
    t = a[left];

    while(i!=j) {
        while (a[j] >= t && i < j)
            j--;
        while (a[i] <= t && i < j)
            i++;
        if (i < j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    a[left] = a[i];
    a[i] = t;
    quicksort(left, i-1);
    quicksort(i+1, right);
}

int main()
{
    int n;

    for(n=0;n<10;n++)
        scanf("%d", &a[n]);
    printf("Before sort: ");
    for(n=0;n<10;n++)
        printf("%d ", a[n]);
    printf("\n");

    quicksort(0, 9);

    printf("After sort: ");
    for(n=0;n<10;n++)
        printf("%d ", a[n]);
    printf("\n");

    return 0;
}