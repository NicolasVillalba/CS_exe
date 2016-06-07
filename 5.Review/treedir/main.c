#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <strings.h>

void printdir(char * pathname, int width)//打印目录
{
	DIR * dir = opendir(pathname);
	if(NULL == dir)
	{
		perror("opendir");
		return;
	}
	struct dirent *p;
	char buf[512];
	while((p = readdir(dir)) != NULL)
	{
		if(!strcmp(p->d_name, ".")|| !strcmp(p->d_name,".."))
		{
			continue;
		}
		if(p->d_type == 4)//目录
		{
			printf("%*s%s\n", width,"", p->d_name);
			bzero(buf, sizeof(buf));//置零函数
			sprintf(buf, "%s%s%s",pathname, "/", p->d_name);
			printdir(buf, width + 4);
		}else {
			printf("%*s%s\n", width,"", p->d_name);
		}
	}
}

int main(int argc, char * argv[])
{
	if(argc != 2)//传递2个参数
	{
		printf("args error");
		return -1;
	}
	printf("%s\n", argv[1]);
	printdir(argv[1], 0);
	return 0;
}
