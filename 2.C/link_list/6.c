#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//将两个有序链表合并成一个有序链表。
typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;


Node phead1 = NULL, ptail1 = NULL;
Node phead2 = NULL, ptail2 = NULL;



/*void link_tail_insert(Node *phead, Node *ptail, int n)*/
/*{*/
/*	Node pnew = (Node)malloc(sizeof(nod));*/
/*	memset(pnew, 0, sizeof(nod));*/
/*	pnew->num = n;*/
/*	if(*ptail == NULL)*/
/*	{*/
/*		*phead = pnew;*/
/*		*ptail = pnew;*/
/*	}else{*/
/*		(*ptail) -> pnext = pnew;*/
/*		*ptail = pnew;*/
/*	}*/
/*}*/




void link_sort_insert(Node *phead, Node *ptail, int n)
{
	Node pcur;
	Node ppre;
	Node pnew = (Node)malloc(sizeof(nod));     
	memset(pnew, 0, sizeof(nod));//结点初始化
   pnew->num = n;
	if(*phead == NULL)//判断为空
	{
		*phead = pnew;
		*ptail = pnew;
	}else if((*phead)->num > n){//插入到头部
		pnew -> pnext = *phead;
		*phead = pnew;
	}else if((*ptail)->num < n){//插入到尾部
		(*ptail) -> pnext = pnew;
		(*ptail) = pnew;
	}else{//插入中间
		pcur = *phead;
		while(pcur != NULL)
		{
			
			if(pcur -> num >n)
			{
				ppre -> pnext = pnew;
				pnew -> pnext = pcur;
				break;
			}
			ppre = pcur;
			pcur = pcur -> pnext;
		}
	}
}


void link_merge(Node *phead, Node *ptail)
{
	Node pscur1 = phead1;
	Node pscur2 = phead2;
	while(pscur1 != NULL)
	{
		int n = pscur1->num;
		link_sort_insert(phead, ptail, n);
		pscur1 = pscur1 -> pnext;
	}
	while(pscur2 != NULL)
	{
		int n = pscur2->num;
		link_sort_insert(phead, ptail, n);
		pscur2 = pscur2 -> pnext;
	}
}


/*void link_merge(Node *phead, Node *ptail)*/
/*{*/
/*	Node pscur1 = phead1;*/
/*	Node pscur2 = phead2;*/
/*	while(pscur1 != NULL && pscur2 != NULL)*/
/*	{*/
/*		if(pscur1 -> num < pscur2->num)*/
/*		{*/
/*			link_tail_insert(&phead, &ptail, pscur1->num);*/
/*			pscur1 = pscur1->pnext;*/
/*		}else if(pscur1->num > pscur2->num){*/
/*			link_tail_insert(&phead, &ptail, pscur2->num);*/
/*			pscur2 = pscur2->pnext;*/
/*		}else {*/
/*			link_tail_insert(&phead, &ptail, pscur2->num);*/
/*			link_tail_insert(&phead, &ptail, pscur1->num);*/
/*			pscur2 = pscur2->pnext;*/
/*			pscur1 = pscur1->pnext;*/
/*		}*/
/*		*/
/*	}*/
/*	if(pscur1 == NULL) {*/
/*		while(pscur2 != NULL) {*/
/*			link_tail_insert(&phead, &ptail, pscur2->num);*/
/*			pscur2 = pscur2->pnext;*/
/*		}*/
/*	}*/
/*	*/
/*	if(pscur2 == NULL) {*/
/*		while(pscur1 != NULL) {*/
/*			link_tail_insert(&phead, &ptail, pscur1->num);*/
/*			pscur1 = pscur1->pnext;*/
/*		}*/
/*	}*/
/*}*/



void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%d ", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}



int main()
{
	Node phead = NULL, ptail = NULL;
	
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead1);
			break;
		}else link_sort_insert(&phead1, &ptail1, num);
	}


	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead2);
			break;
		}else link_sort_insert(&phead2, &ptail2, num);
	}
	link_merge(&phead, &ptail);
	printf("After merging:\n");
	link_show(phead);
	return 0;
}



