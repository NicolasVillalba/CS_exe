#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct student{
    int num;
    struct student *pnext;
}stu, *pstu;



void link_head_insert(pstu *,pstu * ,int);//头插法
void link_tail_insert(pstu *, pstu *, int);//尾插法
void link_show(pstu);


