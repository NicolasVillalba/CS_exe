#include<stdio.h>

typedef struct Student{
    char id[3];
    int score;
}Student;

Student fun(Student s[], int score)
{
    Student tmp = {"", -1};
    for(int i= 0; i < 3; i++)
        if(s[i].score == score) return s[i];
    return tmp;
}

int main()
{
    Student s[3] = {
        {"111",12},
        {"222",66},
        {"333",89}
    };
    Student n = fun(s, 66);
    printf("%s : %d\n", n.id, n.score);
    return 0;
}
