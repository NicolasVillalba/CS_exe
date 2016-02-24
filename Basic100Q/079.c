#include<stdio.h>
#define N 4

typedef struct Student{
    int id, score;
}Student;

Student fun(Student s[])
{
    int score = 101;
    Student tmp;
    for(int i = 0; i < N; i++)
    {
        if(score > s[i].score)
        {
             score = s[i].score;
             tmp = s[i];
        }
    }
    return tmp;
}


int main()
{
    Student s[N] = {
        {111,22},
        {222,55},
        {444,2},
        {555,88}
    };
    Student low = fun(s);
    printf("%d : %d\n", low.id, low.score);
    return 0;
}
