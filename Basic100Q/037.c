#include<stdio.h>

typedef struct Student{
    int id;
    double score[8];
    double ave;
}Student;


void fun(Student *s)
{
    double sum = 0.0;
    for(int i = 0; i < 8; i++)
        sum += s->score[i];
    s->ave = sum / 8;
}

int main()
{
     Student s ={ 122, {85.5, 76.0, 69.5, 85.0, 91.0, 72.0, 64.5, 87.5}};
     fun(&s);
     printf("%0.3lf\n", s.ave);
     return 0;
}
