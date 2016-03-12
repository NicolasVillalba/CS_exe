#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//判断两个链表是否相交, 如果相交, 计算交点

typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node; 


void link_tail_insert(Node *phead, Node *ptail, int n)
{
	Node pnew = (Node)malloc(sizeof(nod));
	memset(pnew, 0, sizeof(nod));
	pnew->num = n;
	if(*ptail == NULL){
		*phead = pnew;
		*ptail = pnew;
	}else{
		(*ptail)->pnext = pnew;
		*ptail = pnew;
	}
}


int link_find_Union(Node phead1, Node phead2)
{
	Node pscur1 = phead1;
	int cnt = 0;
	while(pscur1 != NULL)
	{
		Node pscur2 = phead2;
		while(pscur2 != NULL)
		{
			if(pscur1 == pscur2) 
			{
				printf("%d ", pscur2 -> num);
				cnt++;
			}
			else pscur2 = pscur2->pnext;
		}
		pscur1 = pscur1->pnext;
	}
	if(cnt) return 1;
	else return 0;
}


int main()
{
	Node phead1 = NULL, ptail1 = NULL;
	Node phead2 = NULL, ptail2 = NULL;
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			break;
		}else link_tail_insert(&phead1, &ptail1, num);
	}
	while((scanf("%d", &num)))
	{
		if(num == -1){
			break;
		}else link_tail_insert(&phead2, &ptail2, num);
	}
	if(link_find_Union(phead1, phead2)) printf("The Node has union!\n");
	else printf("The Node doesn't have union!\n");
	return 0;
}
