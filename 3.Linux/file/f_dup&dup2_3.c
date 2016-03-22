/*dup2(int fdold,int fdnew)也是进行描述符的复制，只不过采用此种复制，新的描述符由用户用参数fdnew显示指定，而不是象dup一样由内核帮你选定（内核选定的是随机的）。对于dup2，如果fdnew已经指向一个已经打开的文件，内核会首先关闭掉fdnew所指向的原来的文件。此时再针对于fdnew文件描述符操作的文件，则采用的是fdold的文件描述符。如果成功dup2的返回值于fdnew相同,否则为-1*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    char buf[32] = {0};
    int fda = open("a.txt", O_RDONLY);
    int fdb = open("aaa.txt", O_RDONLY);
    int fdbb = dup(fdb);
    int fda2 = dup2(fda, fdb);//fda2的进程设置成fdb的
    printf("fda:%d  fdb:%d  fdbb:%d  fda2:%d\n", fda, fdb, fdbb, fda2);
    read(fdb, buf, sizeof(buf) - 1);
    //此时fdb已经不再定位aaa.txt而是a.txt
    printf("result:%s", buf);
    
    close(fda);
    close(fdb);
    close(fdbb);
    close(fda2);
    return 0;
}
