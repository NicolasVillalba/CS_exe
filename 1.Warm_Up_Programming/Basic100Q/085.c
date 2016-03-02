#include<stdio.h>

typedef struct Student{
    char id[11];
    int score;
    struct Student *next;
}Student;

double fun(Student *h)
{
    int sum = 0, cnt = 0;
    h = h-> next;
    while(h)
    {
         sum += h -> score;
         ++cnt;
         h = h->next;
    }
    if(cnt == 0) return 0;
    return (double)sum / cnt;
}

int main()
{
     Student c = {"0003", 90, NULL}, b = {"002",90,&c},a={"0001",94, &b}, h = {"", -1, &a};
     printf("AVG: %.2f\n",fun(&h));
     return 0;
}
