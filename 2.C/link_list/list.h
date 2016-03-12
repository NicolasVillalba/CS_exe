#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//增加：头插法，尾插法，
//删除

typedef struct student{
    int num;
    struct student *pnext;
}stu, *pstu;


//插入
void link_head_insert(pstu *,pstu * ,int);//头插法

void link_tail_insert(pstu *, pstu *, int);//尾插法

void link_sort_insert(pstu *, pstu *, int);//有序插入



//删除
void link_delete(pstu *, pstu *, int);


int link_search(pstu, int);

int link_modify(pstu, int , int);

void link_show(pstu);


