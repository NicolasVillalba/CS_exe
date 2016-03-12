#include "func.h"

void sort_begin(int *a){
	int i;
	srand(time(NULL));
	for(i=0;i<N;i++){
		a[i] = rand()%100;
	}
}

void sort_print(int *a){
	int i;
	for(i=0;i<N;i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}

//√∞≈›≈≈–Ú
void sort_bubble(int *a){
	int i,j;
	for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			if(a[i]>a[j]){
				SWAP(a[i],a[j]);
			}
		}
	}
}

//—°‘Ò≈≈–Ú£¨“ª±È÷ªΩªªª“ª¥Œ
void sort_select(int *a){
	int i,j;
	int min_pos;
	for(i=0;i<N;i++){
		min_pos = i;
		for(j=i+1;j<N;j++){
			if(a[min_pos] > a[j]){
				min_pos = j;
			}
		}
		SWAP(a[i],a[min_pos]);
	}
}

//≤Â»Î≈≈–Ú
void sort_insert(int *a){
	int i,j,k,insert_value;
	for(i=1;i<N;i++){
		for(j=0;j<i;j++){
			if(a[i]<a[j]){
				insert_value = a[i];
				for(k=i;k>j;k--){
					a[k] = a[k-1];
				}
				a[j] = insert_value;
				break;
			}
		}
	}
}

//øÏ≈≈
int compare(const void*left,const void*right){
	int *pl =(int *)left;
	int *pr =(int *)right;
	if(*pl>*pr){
		return 1;
	}else if(*pl<*pr){
		return -1;
	}else{
		return 0;
	}
}
