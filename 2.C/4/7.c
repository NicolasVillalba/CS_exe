#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int Count(int n, int m)
{
	while(n != 0 && m != 0)
	{
		return (Count(n - 1, m) + Count(n, m - 1));
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

