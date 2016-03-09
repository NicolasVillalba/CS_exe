#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int Count(int n, int m)
{
	if(n == 0 && m ==1 || n==1&&m==0) return 1;
	else if(m > 0&& n > 0) return (Count(n - 1, m) + Count(n, m - 1));
	else {
			if(n == 0) return Count(n, m - 1);
			else return Count(n - 1, m);
	}
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int count = Count(n, m);
	printf("%d\n", count);
	return 0;
}

