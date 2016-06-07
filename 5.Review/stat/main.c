#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		printf("error args\n");
		return -1;
	}
	struct stat buf;
	memset(&buf, 0, sizeof(buf));
	int ret = stat(argv[1], &buf);
	if(-1 == ret)
	{
		perror("stat");
		return -1;
	}
	printf("%5x %d %5d %5d %ld %s %s\n", buf.st_mode, buf.st_nlink, buf.st_uid, buf.st_gid, buf.st_size, ctime(&buf.st_mtime), argv[1]);
	return 0;
}
