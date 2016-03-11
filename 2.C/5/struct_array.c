#include<stdio.h>


int main()
{
    struct student{
        int num;
        char name[20];
    };
    struct student stu[2] = {{1000, "zhangsan"}, {1001, "lisi"}};
    struct student *p;
    p = stu;//数组或者结构体不需要取地址符，p+1 = &stu[1]
    for(int i = 0; i < 2; i++)
        printf("the num = %d, name = %s\n", (*(p + i)).num, (*(p + i)).name);
    //或者p -> num;
    return 0;
}
