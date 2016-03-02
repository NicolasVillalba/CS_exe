#include<stdio.h>
#define N 3

typedef struct Student{
    int id, score;
}Student;

Student a[N] = {
    {111,62},
    {222,99},
    {333,88}
};

int fun(Student b[], int begin, int end)
{
    int cnt = 0;
     for(int i = 0; i < N; i++)
         if(a[i].score <= end && a[i].score >= begin) b[cnt++] = a[i];
     return cnt;
}

int main()
{
    Student b[N];
    for(int i = 0; i < N; i++)
    {
        b[i].id = 0;
        b[i].score = 0;
    }
    int begin, end;
    scanf("%d %d",&begin, &end);
    int n = fun(b, begin, end);
    printf("%d\n",n);
    for(int i = 0; i < n; i++)
        printf("%d : %d\n", b[i].id, b[i]. score);
    return 0;
}
