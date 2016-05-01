#include <stdio.h>
void PrintWeek();
void PrintMonth(int,int,int,int);
void SetMonthDay(int arr[]);

int main()
{
    int BlankCount[4];
    int months[12];

    SetMonthDay(months);

    BlankCount[0]=1;
    BlankCount[1]=(BlankCount[0]+months[1]+months[2]+months[3])%7;
    BlankCount[2]=(BlankCount[1]+months[4]+months[5]+months[6])%7;
    BlankCount[3]=(BlankCount[2]+months[7]+months[8]+months[9])%7;

    printf("==============正月============= ==============二月============= ==============三月=============\n");
    PrintWeek();
    PrintMonth(BlankCount[0],months[0],months[1],months[2]);
    printf("==============四月============= ==============五月============= ==============六月=============\n");
    PrintWeek();
    PrintMonth(BlankCount[1],months[3],months[4],months[5]);
    printf("==============七月============= ==============八月============= ==============九月=============\n");
    PrintWeek();
    PrintMonth(BlankCount[2],months[6],months[7],months[8]);
    printf("==============十月============= ============十 一 月============ ==============腊月=============\n");
    PrintWeek();
    PrintMonth(BlankCount[3],months[9],months[10],months[11]);

}

void PrintWeek()
{
    int count;
    for(count=0;count<3;count++)
        printf("周日 周一 周二 周三 周四 周五 周六 \t");
    printf("\n");
}

void SetMonthDay(int arr[])
{
    int g;
    for(g=0;g<12;g++)
        arr[g]=30;
    arr[1]=29;
}

void PrintMonth(int blank, int fmonth, int smonth, int tmonth)
{
    int rowcount, blank2, blank3, i, j;
    int flagA=0, flagB=0;
    int day1=1, day2=1, day3=1;

    for(i=0;i<blank;i++)
        printf("    ");

    for(rowcount=0;rowcount<6;rowcount++)
    {
        while((day1+blank)%7!=0)
        {
            if(day1<=fmonth)
                printf("%3d ", day1);
            else
                printf("    ");
            day1++;
        }

        if(day1<=fmonth)
            printf("%3d \t", day1);
        else
            printf("    \t");
        day1++;

        while(!flagA)//
        {
            blank2 = (fmonth+blank)%7;
            for(j = 1;j<=blank2;j++)
                printf("    ");
            flagA=1;
        }

        while((day2+blank2)%7!=0)
        {
            if(day2<=smonth)
                printf("%3d ", day2);
            else
                printf("    ");
            day2++;
        }

        if(day2<=smonth)
            printf("%3d \t", day2);
        else
            printf("    \t");
        day2++;

        if(flagB == 0)
        {
            blank3 = (smonth+blank2)%7;
            for(j = 1;j<=blank3;j++)
                printf("    ");
            flagB=1;
        }

        while((day3+blank3)%7!=0)
        {
            if(day3<=tmonth)
                printf("%3d ", day3);
            else
                printf("    ");
            day3++;
        }

        if(day3<=tmonth)
            printf("%3d \n", day3);
        else
            printf("    \n");
        day3++;
    }
}
