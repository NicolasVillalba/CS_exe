#include<stdio.h>

int main()
{
    int AverageYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int LeapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    printf("please input the year of your birthday:\n");
    scanf("%d", &year);
    printf("please input the month of your birthday:\n");
    scanf("%d", &month);
    printf("please input the day of your birthday:\n");
    scanf("%d", &day);
    int cnt = 0;
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
         for(int  i = 0; i < month - 1; i++)
             cnt += LeapYear[i];
         cnt += day;
    }else{
         for(int i = 0; i < month - 1; i++)
             cnt += AverageYear[i];
         cnt += day;
    }
    printf("%d\n", cnt);
    return 0;
}
