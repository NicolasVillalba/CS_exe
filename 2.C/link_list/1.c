#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5


struct Course{
	int score1;
	int score2;
	int score3;
	int sum;
};


struct Student{
	int num;
	char name[20];
	struct Course course;
};


void sort_bubble_num(struct Student *stu)//以学号排名，学号最低的排在前面
{
	struct Student temp;
	temp.num = -1;
	for(int i = 0; i < N; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			if(stu[i].num > stu[j].num){
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
}


void sort_bubble_sum(struct Student *stu)//以分数排名,最高的排在前面
{
	struct Student temp;
	temp.course.sum = -1;
	for(int i = N - 1; i >= 0; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(stu[i].course.sum  < stu[j].course.sum){
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
}


void printAllInfo(struct Student stu[])//输出所有信息
{
	for(int i = 0; i < N; i++)
	{
		printf("num = %d, name = %s, score1 = %d, score2 = %d, score3 = %d, sum = %d\n", stu[i].num, stu[i].name, stu[i].course.score1, stu[i].course.score2, stu[i].course.score3, stu[i].course.sum);
	}
}


void printHighScore(struct Student stu[])//输出每门课程的最高分的学生的信息
{
	struct Student s1, s2, s3;
	s1 = stu[0];
	s2 = stu[0];
	s3 = stu[0];
	for(int i = 1; i < N; i++)
	{
		if(s1.course.score1 < stu[i].course.score1) s1 = stu[i];
		if(s2.course.score2 < stu[i].course.score2) s1 = stu[i];
		if(s3.course.score3 < stu[i].course.score3) s1 = stu[i];
	}
	printf("the highest score in course1 is num = %d, name = %s, score1 = %d, score2 = %d, score3 = %d, sum = %d\n", s1.num, s1.name, s1.course.score1, s1.course.score2, s1.course.score3, s1.course.sum);
	printf("the highest score in course2 is num = %d, name = %s, score1 = %d, score2 = %d, score3 = %d, sum = %d\n", s2.num, s2.name, s2.course.score1, s2.course.score2, s2.course.score3, s2.course.sum);
	printf("the highest score in course3 is num = %d, name = %s, score1 = %d, score2 = %d, score3 = %d, sum = %d\n", s3.num, s3.name, s3.course.score1, s3.course.score2, s3.course.score3, s3.course.sum);
}



void printAverageScore(struct Student stu[])//打印出所有课程的平均分
{
	float av1 = 0.0, av2 = 0.0, av3 = 0.0;
	for(int i = 0; i < N ; i++)
	{
		av1 += stu[i].course.score1;
		av2 += stu[i].course.score2;
		av3 += stu[i].course.score3;
	}
	printf("score1Average = %.2lf\n", av1/N);
	printf("score2Average = %.2lf\n", av2/N);
	printf("score3Average = %.2lf\n", av3/N);
}



void Menu()
{
	printf("**************************************************\n");
	printf("**************************************************\n");
	printf("****************1.按照学号递增输出全部学生信息**************\n");
	printf("****************2.输出每门课程最高分的学生的信息*************\n");
	printf("****************3.输出每门课程的平均分************************\n");
	printf("****************4.按照总分输出学生排名************************\n");
	printf("****************5.帮助**************************************\n");
	printf("****************6.退出请输入6*******************************\n");
	printf("****************************************************\n");
	printf("**************************************************\n");
	printf("请输入相关命令：\n");
}




int main()
{
	struct Student stu[N];
	printf("Please input five students' information:\n");
	for(int i = 0; i < N; i++)
	{
		scanf("%d%s%d%d%d", &stu[i].num, stu[i].name, &stu[i].course.score1, &stu[i].course.score2, &stu[i].course.score3);
		stu[i].course.sum = stu[i].course.score1 + stu[i].course.score2 + stu[i].course.score3;
	}
	Menu();
	int n = 0;
	while(scanf("%d", &n))
	{
		switch(n) {
			case 1:
					sort_bubble_num(stu);
					printAllInfo(stu);
					break;
			case 2:
					printHighScore(stu);
					break;
			case 3:
					printAverageScore(stu);
					break;
			case 4:
					sort_bubble_sum(stu);
					printAllInfo(stu);
					break;
			case 5:
					Menu();
					break;
			case 6:
					return 0;
		}
	}
	return 0;
}
