#include<stdio.h>
#define N 4

typedef struct Student{
    int id, score;
}Student;

int fun(Student s[], Student h[])
{
    int cnt = 0;
    int lowScore = s[0].score;
    for(int i = 0; i < N; i++)
        if(lowScore > s[i].score) lowScore = s[i].score;
    for(int i = 0; i < N; i++)
    {
         if(s[i].score == lowScore) h[cnt++] = s[i];
    }
    return cnt;
}

int main()
{
    Student s[N] = {
        {111,11},
        {222,33},
        {444,33},
        {333,11}
    };
    Student t[N];
    for(int i = 0; i < N; i++)
    {
         t[i].id = 0;
         t[i].score = 0;
    }
    int n = fun(s, t);
    printf("%d\n", n);
    for(int i = 0; i< n; i++)
        printf("%d : %d\n", t[i].id, t[i].score);
    return 0;
}
