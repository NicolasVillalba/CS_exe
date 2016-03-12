#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用头插法建立链表
typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;


void link_show(Node phead)
{
	Node pscur;
	pscur = phead;
	while(pscur != NULL)
	{
		printf("%3d", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


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


int main()
{
	Node phead, ptail;
	int num;
	phead = NULL;
 	ptail = NULL;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			return 0;
		}else link_head_insert(&phead, &ptail, num);
	}
}


