#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#define SWAP(a,b)	{int tmp;tmp=a;a=b;b=tmp;}
void sort_print(int *);

void sort_begin(int *);

void sort_bubble(int *);

void sort_select(int *);

void sort_insert(int *);

int compare(const void*,const void*);
