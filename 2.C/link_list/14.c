//大整数加法。(计算两个整数(该整数的值可能超过一个整型变量所能表示的范围)的加法)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;


Node phead = NULL, ptail = NULL;
Node phead1 = NULL, ptail1 = NULL;
Node phead2 = NULL, ptail2 = NULL;



void link_head_insert(Node *phead, Node *ptail, int n)
{
		Node pnew = (Node)malloc(sizeof(nod));
		memset(pnew, 0, sizeof(nod));
		pnew->num = n;//以上为初始化需要插入的结点
		if(*phead == NULL)
		{
			*phead = pnew;
			*ptail = pnew;			
		}else{
			pnew -> pnext = *phead;
			*phead = pnew;
		}
}


void link_tail_insert(Node *phead, Node *ptail, int n)
{
	Node pnew = (Node)malloc(sizeof(nod));
	memset(pnew, 0, sizeof(nod));
	pnew->num = n;
	if(*ptail == NULL)
	{
		*phead = pnew;
		*ptail = pnew;
	}else{
		(*ptail) -> pnext = pnew;
		*ptail = pnew;
	}
}


void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%d", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


void link_plus()
{
	Node pscur1 = phead1;
	Node pscur2 = phead2;
	int temp = 0;
	int n = 0;
	while(pscur1 != NULL && pscur2 != NULL)
	{
		n += (temp + pscur1->num + pscur2->num)%10;
		link_head_insert(&phead, &ptail, n);
		temp = n / 10 ;
		pscur1 = pscur1->pnext;
		pscur2 = pscur2->pnext;
	}
	if(pscur1 == NULL){
		while(pscur2 != NULL)
		{
			n += (temp + pscur2->num)%10;
			link_head_insert(&phead, &ptail, n);
			temp = n / 10 ;
			pscur2 = pscur2->pnext;
		}
	}
	if(pscur2 == NULL){
		while(pscur1 != NULL)
		{
			n += (temp + pscur1->num)%10;
			link_head_insert(&phead, &ptail, n);
			temp = n / 10 ;
			pscur1 = pscur1->pnext;
		}
	}
}


int main()
{
	int num;
	printf("Please input a integer with space between each letter:\n");
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead1);
			break;
		}else link_tail_insert(&phead1, &ptail1, num);
	}
	printf("Please input another integer with space between each letter:\n");
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead2);
			break;
		}else link_tail_insert(&phead2, &ptail2, num);
	}
	link_plus();
	printf("The plus is:\n");
	link_show(phead);
	return 0;
}
