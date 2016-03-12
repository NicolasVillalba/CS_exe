#include "func.h"

void main(){
	int a[N];
	int t1,t2;
	sort_begin(a);
	sort_print(a);
	t1 = clock();
	sort_bubble(a);
	//sort_select(a);
	//sort_insert(a);
	//qsort(a,N,sizeof(int),compare);
	t2 = clock();
	sort_print(a);
	//sort_print(a);
	printf("the clock is %d\n",t2-t1);
}
