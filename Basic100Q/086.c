#include<stdio.h>
#include<math.h>
#define N 10

double fun(double a[])
{
    double sum = 0.0;
    for(int i = 0; i < 10; i++)
        sum += a[i];
    double av = sum / N;
    sum = 0.0;
    for(int i = 0; i < N; i++)
    {
        sum += (a[i] - av) * (a[i] - av);
    }
    double s = sum / N;
    return pow(s, 0.5);
}

int main()
{
     double a[N] = {95.0,89.0, 76.0, 65.0, 88.0, 72.0,85.0,81.0,90.0,56.0};
     double s = fun(a);
     printf("%.6lf\n", s);
     return 0;
}
