#include<stdio.h>
#define m 5

int score[m] = {40, 50, 60, 70, 80};
int below[m];

void fun(const int score[], int below[], int M)
{
    int aver = 0;
    int n = m;
    for(int i = 0; i < M; i++) aver += score[i];
    aver /= M;
    for(int i = 0; i < M; i++)
         if(score[i] < aver) below[i] = score[i];
}

int main()
{
    int cnt = 0;
    for(int i = 0; i < m; ++i)
    {
         below[i] = -1;
    }
    fun(score, below, m);
    for(int i = 0; i < m; i++)
        if(below[i] != -1)
        {
            printf("%d\n", below[i]);
            cnt ++;
        }
    printf("There %d students below the average line.\n",cnt);
    return 0;
}
