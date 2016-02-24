#include<stdio.h>
#define N 3

typedef struct Student{
    int id, score;
}Student;

int fun(Student s[], Student b[])
{
    int n = 0;
    int av = 0;
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += s[i].score;
    av = sum / N;
    for(int i = 0; i < N; i++)
        if(s[i].score < av) b[n++] = s[i];
    return n;
}

int main()
{
    Student s[N] = {
        {111, 22},
        {222, 66},
        {333, 99}
    };
    Student b[N];
    for(int i = 0; i < N; i++)
    {
         b[i].id = 0;
         b[i].score = 0;
    }
    int n = fun(s, b);
    printf("%d\n",n);
    for(int i = 0; i < N && b[i].id != 0; i++)
        printf("%d, %d\n", b[i].id, b[i].score);
    return 0;
}
