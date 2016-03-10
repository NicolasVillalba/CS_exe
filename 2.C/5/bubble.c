#include "bubble.h"


void Bubble_begin(int *a)
{
	int i;
	srand(time(NULL));
	for(int i = 0; i < N; i++)
		a[i] = rsand() % 100;
}	


void sort_print(int *a)
{
	int i;	
	for(i = 0; i < N; i++)
		printf("%3d", a[i]);
}


void Bubble_Sort(int *a)
{
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
