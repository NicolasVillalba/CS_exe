#include<stdio.h>
#define N 11

void fun(int age[], int a[N])
{
    for(int i = 0; i < N; i++)
    {
        if(a[i] <= 9 && a[i] >= 0) age[0]++;
        else if(a[i] <= 19 && a[i] >= 10) age[1]++;
        else if(a[i] <= 29 && a[i] >= 20) age[2]++;
        else if(a[i] <= 39 && a[i] >= 30) age[3]++;
        else if(a[i] <= 49 && a[i] >= 40) age[4]++;
        else if(a[i] <= 59 && a[i] >= 50) age[5]++;
        else if(a[i] <= 69 && a[i] >= 60) age[6]++;
        else if(a[i] <= 79 && a[i] >= 70) age[7]++;
        else if(a[i] <= 89 && a[i] >= 80) age[8]++;
        else if(a[i] <= 99 && a[i] >= 90) age[9]++;
        else age[10]++;
    }
}

int main()
{
    int age[N];
    for(int i = 0; i < N; i++)
        age[i] = 0;
    int a[N] = {1,12,22,32,42,55,22,77,88,100,88};
    fun(age, a);
    for(int i = 0; i < N; i++)
        printf("age[%d] : %d\n", i, age[i]);
    return 0;
}
