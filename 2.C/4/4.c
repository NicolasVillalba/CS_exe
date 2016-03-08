#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 15

int j = 1;

int *DeleteRepeatN(int *a)
{
	int i;
	int temp = a[0];
	for(i = 1; i < n; i++)
	{
		if(a[i] == temp) continue;
		else{
			temp = a[i];
			a[j++] = a[i];
		}
	}
	return a;
}


int main()
{
	int a[n] = {1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6};
	DeleteRepeatN(a);
	printf("%d", a[0]);
	for(int i = 1; i < j; i++ )
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
