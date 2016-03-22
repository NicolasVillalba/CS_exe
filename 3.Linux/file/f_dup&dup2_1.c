#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char*argv[])
{
    char buf[32] = {0};
    int fda = open("d.txt", O_RDWR);
    //d.txt的内容为：helloworld
    int fdaa =dup(fda);
    read(fda, buf, 4);
    puts(buf);
    close(fda);
    
    lseek(fdaa, 0, SEEK_CUR);
    read(fdaa, buf, sizeof(buf));
    puts(buf);
    close(fdaa);
    return 0;
    
    //假设d.txt中的内容为：hello world.上面的例子会发现第一次输出的结果是hell。关闭close(fda)的时候，文件实际上还没有真正的关闭，此时文件指针已经向后移动了。执行第二次read命令将o world读出来，最后关闭fdaa。
}
