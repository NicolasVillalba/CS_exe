c语言上机考试画重点（持续更新，目前是三题中第一题会考的题型）
==================


##[1.1.c](1.1.1.c):质因数分解，比如6的质因数为2和3，给定一个数，输出质因数


```c
#include <stdio.h>

int main(){
	int n;  // 用户输入的整数
	int i;  // 循环标志

	printf("输入一个整数：");
	scanf("%d",&n);
	printf("%d=",n);


    //以下部分是重点，即求质因数的过程
	// n>=2才执行下面的循环
	for(i=2; i<=n; i++){//本循环是从2到n才结束
		while(n!=i){//
			if(n%i==0){
				printf("%d*",i);
				n=n/i;
			}else
				break;
		}
	}
	printf("%d\n",n);
	//

	return 0;
}
```

##[1.2.c](1.2.c):两数组合并到新数组,本题是将数组a和b的数字存储进c数组中

```c
//两数组合并到新数组,本题是将数组a和b的数字存储进c数组中
//考点：数组的定义，使用，数组的起点编号（比如数组h[6],起始为h[0], 最后一个为h[5],数组中元素个数为6个）

#include<stdio.h>


int main()
{
//定义2个数组，并且初始化
    int a[5] = {1,3,5,6,8};
    int b[3] = {2,5,10};
    

//定义第三个数组并且初始化
    int c[10] = {0};//这样定义表示所有的元素都为0
    
    //将a置入第三个数组c中
    int i,n;
    for(i = 0; i < 5; i++)
    {
        c[i] = a[i];
    }
    n = i;//记录好c数组的下标
    
    //将b置入第三个数组c中
    for(i = 0; i < 3; i++)
    {
        c[i + n] = b[i];
    }
    
    //最后输出c数组，判断0则停止
    int j = 0;
    while(c[j] != 0)
    {
        printf("c[%d] = %d\n", j, c[j++]);
    }
    return 0;
}
```


##[1.3.c](1.3.c):将一个乱序的数组利用**冒泡排序**排序后按照从小到大顺序输出。

```c
//本体是对数组中的元素进行排序
//考点：冒泡排序
//利用第二题的数组排序，即本题是利用1.2.c题目进行延伸，要求最后的数组有序


#include<stdio.h>


int main()
{
    int c[10] = {3,6,2,1,4,5,3,9,56,10};
    
    //冒泡排序，是重点
    //冒泡排序的思想是像鱼吐泡泡，将大的数字放到后面去。
    int i,j;
    for(i = 0; i < 10; i++)//首先i从数组首元素开始，到最后结束
    {
        for(j = i+1; j < 10; j++)//然后j从i的下一个开始遍历到最后
        {
            if(c[i] > c[j])//假如前面一个比后面一个大，就交换他们使得前面一个小于后面一个
            {
                //此三句代码为交换两个数字的过程
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    
   //输出排序好的数组
   for(i = 0 ; i < 10; i++)
   {
        printf("%d ", c[i]);
   }
   printf("\n");
   return 0;
}
```

##[2.1.c](2.1.c)带头节点的单链表，生成链表，遍历链表，删除链表节点

```c
//带头节点的单链表，生成链表，遍历链表，删除链表最大节点
//链表的考点在于结构体，然后是指针

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//利用结构体定义一个链表结点
typedef struct node{
    int num;
    struct node *pnext;
}nod, *Node;



void link_head_insert(Node *phead,Node *ptail, int n)//头插法，就是将需要增加的数据加从链表的头部插入
{
        Node pnew = (Node)malloc(sizeof(nod));
        memset(pnew, 0, sizeof(nod));//结点初始化
        pnew->num = n;
        if(*phead == NULL)
        		{
            *phead = pnew;
            *ptail = pnew;
        }else{
            pnew -> pnext = *phead;
            *phead = pnew;
        }
}



void link_tail_insert(Node *phead, Node *ptail, int n)//尾插法，将需要插入链表的数据插入链表的尾部
{
	Node pnew = (Node)malloc(sizeof(nod));     
	memset(pnew, 0, sizeof(nod));//结点初始化
    pnew->num = n;
	if(*ptail == NULL)
	{
		  *phead = pnew; 
        *ptail = pnew;		
	}else{
			(*ptail) -> pnext = pnew;//将我们新增的结点赋值给原有结点的pnext
			*ptail = pnew;//将新结点变为尾部
	}
}



void link_sort_insert(Node *phead, Node *ptail, int n)//有序插入，按照插入数字的大小插入链表，就是最后得到的链表是从小到大排列的
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




//删除
//空的时候
//不为空的时候，开始遍历
void link_delete(Node *phead, Node *ptail, int n)//删除链表中的的数据n
{
	Node ppre = NULL;
	Node pcur;
	if(*phead == NULL) {
		printf("the link is empty");	
	}else{
		pcur = *phead;
		while(pcur != NULL)
		{
			if(pcur -> num ==n)
			{
				if(ppre ==NULL)
				{
					*phead = pcur -> pnext;
				}else{
					ppre -> pnext = pcur -> pnext;
				}
				free(pcur);
				pcur = NULL;
				return;
			}
				ppre = pcur;
				pcur = pcur -> pnext;
		}
		printf("THis Node doesn't exist!\n'");
	}
}




int link_search(Node phead, int n)//查找链表
{
	while(phead != NULL)
	{
		if(phead -> num == n)
		{
			return 1;
		}
	}
	return 0;
}



void link_show(Node phead)//显示链表
{
     Node pscur;
     pscur = phead;
     while(pscur != NULL)
     {
          printf("%3d", pscur -> num);
          pscur = pscur -> pnext;
     }
     printf("\n");
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////
//以上所有的都是定义函数，以下为主函数
int main()
{
    Node phead, ptail;
    int num;
    phead = NULL;
    ptail = NULL;
    //有序创建链表
    printf("请输入5个数字创建链表：\n");
    for(int i = 0; i < 5; i++)
    {
        int n;
        scanf("%d", &n);
        link_sort_insert(&phead, &ptail, n);
    }
    
    //调用显示链表函数
    link_show(phead);
    
    int m;
    printf("请输入你想从链表删除的数：\n");
    scanf("%d", &m);
    link_delete(&phead, &ptail, m);
    printf("删除之后的链表为:\n");
    
    //调用显示链表函数
    link_show(phead);
    
    return 0;
}
```




##[3.1.c](3.1.c)文件操作，即将需要信息从文件读取，或者将需要的信息写入文件，**重点看c语言书的338页的10.1题**，**339页的10.2题**，**346页的10.4题**，那个代码一定要自己在编译器里面敲一遍然后运行

```c
//文件读写都是有一定的套路的，参考那本红色c语言书，请牢记以下读写文件

//**重点看c语言书的338页的10.1题**，**339页的10.2题**，**346页的10.4题**，那个代码一定要自己在编译器里面敲一遍然后运行
//

#include<stdio.h>


int main()
{
    FILE *fp;//创建一个文件指针，前面那个FILE一定是大写的
    fp = fopen("test.txt", "r");
    //重点语句fopen("test.txt", "r");一共有2个变量，第一个是文件名字（文件要和代码存储在同一个文件夹里面），第二个变量是读写类型，r=read，w=write，这里是打开一个文件是读,只读打开的话只能读取文件里面的信息，不能写进入
    //
    
    
    
    if(NULL == fp){//这里是判断这个文件有没有被程序打开，如果没有打开则打印没打开的信息，然后退出程序运行
        perror("open failed！\n");
        return 0;
    }else{
        printf("Open success!\n");
    }
    
    return 0;
    
}
```

