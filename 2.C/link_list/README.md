> 2. 用尾插法建立链表。

```c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用尾插法建立链表。
typedef struct student{
	int num;
	struct student *pnext;
}stu, *pstu;

void link_tail_insert(pstu *phead, pstu *ptail, int n)
{
	pstu pnew = (pstu)malloc(sizeof(stu));
	memset(pnew, 0, sizeof(stu));
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



void link_show(pstu phead)
{
	pstu pscur;
	pscur = phead;
	while(pscur != NULL)
	{
		printf("%3d", pscur -> num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


int main()
{
	pstu phead, ptail;
	int num;
	phead = NULL;
 	ptail = NULL;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			return 0;
		}else link_tail_insert(&phead, &ptail, num);
	}
}

```

> 3. 用头插法建立链表。

```c
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


```

> 4. 用有序插入建立链表。

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用有序插入建立链表。
typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;



void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%3d", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


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
		}else link_sort_insert(&phead, &ptail, num);
	}
}
```

> 5. 删除指定的某个结点。

```c
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
		printf("%d ", pscur-> num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


void link_delete(Node *phead, Node *ptail, int n)
{
	Node ppre = NULL;
	Node pscur;
	if(*phead == NULL){
		printf("The link is empty\n");
	}else{
		pscur = *phead;
		while(pscur != NULL)
		{
			if(pscur -> num == n){
			if(pscur == NULL)
			{
				*phead = pscur -> pnext;
			}else{
				ppre -> pnext = pscur -> pnext;
			}
			free(pscur);
			pscur = NULL;
			return;
			}
		ppre = pscur;
		pscur = pscur -> pnext;
		}
		printf("This Node doesn't exist!\n'");
	}
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
			int n = 0;
			printf("Please input the number you want to remove in the node:\n");
			scanf("%d", &n);
			link_delete(&phead, &ptail, n);
			printf("after delete\n");
			link_show(phead);
			return 0;
		}else link_head_insert(&phead, &ptail, num);
	}
}



```

> 6. 将两个有序链表合并成一个有序链表。

```c
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



```

> 7. 将一个链表逆置。

如: 1->2 ->3 ->4 ->5 ->NULL, 输出: 5 -> 4 -> 3 ->2 ->1 -> NULL ;

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



///将一个链表逆置。
//如: 1->2 ->3 ->4 ->5 ->NULL, 输出: 5 -> 4 -> 3 ->2 ->1 -> NULL ;
typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;

Node phead1 = NULL, ptail1 = NULL;

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


void link_reverse(Node *phead, Node *ptail)
{
	while(phead1 != NULL)
	{
		link_head_insert(phead, ptail, phead1->num);
		phead1 = phead1->pnext;
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
		}else link_tail_insert(&phead1, &ptail1, num);
	}
	link_reverse(&phead, &ptail);
	printf("After reverse:\n");
	link_show(phead);
	return 0;
}

```

> 8. 找出链表的倒数第四个节点

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;


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



void link_findNode(Node phead)
{
	Node pscur1 = phead;
	Node pscur2 = phead;
	for(int i = 0; i < 4; i++)
	{
		if(pscur2 == NULL) 
		{
			printf("The Node is less than four nodes.\n"); 	
			return;
		}
		pscur2 = pscur2->pnext;
	}
	while(pscur2 != NULL)
	{
		pscur1 = pscur1 -> pnext;
		pscur2 = pscur2-> pnext;
	}
	printf("The Node is %d\n", pscur1->num);
}


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
			link_show(phead);
			break;
		}else link_tail_insert(&phead, &ptail, num);
	}
	link_findNode(phead);
	return 0;
}
```

> 9. 找出链表的中间节点

```c
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
```

> 10. 判断单链表是否有环

```c
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


```

> 11. 判断两个链表是否相交, 如果相交, 计算交点

```c
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
```

> 12. 删除单链表中重复的元素

```c
//删除单链表中重复的元素
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;


void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%3d", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


/*void link_tail_insert(Node *phead, Node *ptail, int n)*/
/*{*/
/*	Node pnew = (Node)malloc(sizeof(nod));*/
/*	memset(pnew, 0, sizeof(nod));*/
/*	pnew->num = n;*/
/*	if(*ptail == NULL)*/
/*	{*/
/*		*ptail = pnew;*/
/*		*phead = pnew;*/
/*	}else{*/
/*		(*ptail)->pnext = pnew;*/
/*		*ptail = pnew;*/
/*	}*/
/*}*/




/*void link_delete(Node *phead, Node *ptail, int n)*/
/*{*/
/*	Node ppre = NULL;*/
/*	Node pscur;*/
/*	pscur = *phead;*/
/*	while(pscur != NULL)*/
/*	{*/
/*		if(pscur -> num == n){*/
/*		if(pscur == NULL)*/
/*		{*/
/*			*phead = pscur -> pnext;*/
/*		}else{*/
/*			ppre -> pnext = pscur -> pnext;*/
/*		}*/
/*		free(pscur);*/
/*		pscur = NULL;*/
/*		return;*/
/*		}*/
/*	ppre = pscur;*/
/*	pscur = pscur -> pnext;*/
/*	}*/
/*}*/





/*void link_delete_union(Node *phead, Node *ptail)*/
/*{*/
/*	Node *pscur = phead;	*/
/*	if(pscur == NULL){*/
/*		printf("The Node is empty.\n");*/
/*		return;*/
/*	}*/
/*	while(pscur != NULL)*/
/*	{*/
/*		Node *pscur1 = (pscur)-> pnext;*/
/*		while(*pscur1 != NULL)*/
/*		{*/
/*			if((*pscur)->num == (*pscur1)->num) link_delete(phead, ptail, (*pscur1)->num);*/
/*			else *pscur1 = (*pscur1)->pnext;*/
/*		}*/
/*		*pscur = (*pscur)->pnext;*/
/*	}*/
/*}*/



void link_sort_insert_withoutUnion(Node *phead, Node *ptail, int n)
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
			if(pcur->num == n) return;
			if(pcur -> num > n)
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






int main()
{
	Node phead = NULL, ptail = NULL;
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			break;
		}else link_sort_insert_withoutUnion(&phead, &ptail, num);
	}
	return 0;
}
```

> 13. 将一个链表拆分(将链表奇数位置上的节点构成一个链表,偶数位置上的节点构成另一
个链表)
例如:L:1 -> 2 -> 3 ->4 ->5 ->6 ->7 ->8 ->9 -> NULL
L1: 1 ->3 ->5 ->7 ->9 -> NULL ;
L2: 2 ->4 ->6 ->8 -> NULL

```c
//将一个链表拆分(将链表奇数位置上的节点构成一个链表,偶数位置上的节点构成另一
//个链表)
//例如:L:1 -> 2 -> 3 ->4 ->5 ->6 ->7 ->8 ->9 -> NULL
//L1: 1 ->3 ->5 ->7 ->9 -> NULL ;
//L2: 2 ->4 ->6 ->8 -> NULL
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

void link_desprate()
{
	int cnt = 1;
	Node pscur = phead;
	while(pscur != NULL)
	{
		if(cnt%2 == 1) link_tail_insert(&phead1, &ptail1, pscur->num);
		else link_tail_insert(&phead2, &ptail2, pscur->num);
		pscur = pscur->pnext;
		cnt++;
	}
}


void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%3d", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}



int main()
{
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			break;
		}else link_tail_insert(&phead, &ptail, num);
	}
	link_desprate();
	link_show(phead1);
	link_show(phead2);
	return 0;
}
```

> 14.大整数加法。(计算两个整数(该整数的值可能超过一个整型变量所能表示的范围)的
加法)

```c
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
```

