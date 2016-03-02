#include<stdio.h>
#define N 3

typedef struct Student{
    int id;
    int score;
}Student;


void fun(Student s[])
{
    Student tmp = s[0];
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            if(s[i].score < s[j].score)
            {
                 tmp = s[j];
                 s[j] = s[i];
                 s[i] = tmp;
            }
}

int main()
{
    Student s[N] = {
        {111, 66}, {222, 99}, {333, 45}
    };
    fun(s);
    for(int i = 0; i < N; i++)
        printf("%d : %d\n", s[i].id, s[i].score);
    return 0;
}
