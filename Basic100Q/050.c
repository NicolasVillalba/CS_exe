#include<stdio.h>
#define N 3

typedef struct Student{
    int id, score;
}Student;

int fun(Student a[])
{
    int n = a[0].score;
    int cnt = 0;
    for(int i = 1; i < N; i++)
    {
        if(n < a[i].score)
        {
             n = a[i].score;
             cnt = i;
        }
    }
    return cnt;
}

int main()
{
    Student s[N] = {
        {111, 55},
        {222, 44},
        {333, 99}
    };
    int n = fun(s);
    printf("%d, %d\n", s[n].id, s[n].score);
    return 0;
}
