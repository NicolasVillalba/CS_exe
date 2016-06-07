 ///
 //
 /// @file    fopen_fclose.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("error args!\n");
		return -1;
	}
	FILE *fp;
	fp = fopen(argv[1], "wb+");
	
	{
		perror("fopen");
		return -1;
	}
	char buf[128];
	bzero(buf, sizeof(buf));
	int ret;
	strcpy(buf,"Hellossss");
	ret = fwrite(buf, sizeof(char),strlen(buf),fp);//fwrite
	if(ret <= 0)
	{
		perror("fwrite");
		return -1;
	}


	char readbuf[128];
	bzero(buf, sizeof(buf));
	ret = fread(buf, sizeof(char), strlen(buf), fp);
	if( ret <= 0)
	{
		perror("fread\n");
		return -1;
	}
	printf("fread = %s\n", readbuf);
	fclose(fp);
	return 0;
}
