#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;



//判断单链表是否有环
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


int link_find_circle(Node phead)
{
	Node pscur = phead;
	Node pscurStatic = phead;
	while(pscur != NULL)
	{
		if(pscur == pscurStatic) return 1;
		else pscur = pscur->pnext;
	}
	return 0;
}



int main()
{
	Node phead = NULL, ptail = NULL;
		int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			break;
		}else link_tail_insert(&phead, &ptail, num);
	}
	ptail -> pnext = phead;
	if(link_find_circle(phead)) printf("The Node has circle!\n");
	else printf("The Node doesn't have circle!\n");
	return 0;
}


