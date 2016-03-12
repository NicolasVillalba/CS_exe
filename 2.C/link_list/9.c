#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;




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


void link_find_bet(Node phead)
{
	int cnt = 0;
	Node pscur = phead;
	Node pscurFast = phead -> pnext;
	while(pscurFast != NULL)
	{
		pscurFast = pscurFast->pnext;
		pscur = pscur->pnext;
		if(pscurFast != NULL) pscurFast = pscurFast->pnext;
		else break;
	}
	printf("The node in the middle Node is %d\n", pscur->num);
}


int main()
{
	Node phead = NULL, ptail = NULL;
	
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			break;
		}else link_tail_insert(&phead, &ptail, num);
	}
	link_find_bet(phead);
	return 0;
}
