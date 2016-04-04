#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>


int main(int argc, char*argv[])
{
    if(argc != 2)
    {
        printf("error args\n");
        return -1;
    }
    int ret;
    ret = kill(atoi(argv[1]), atoi(argv[2]));
    if(ret != 0)
    {
        perror("kill");
        return -1;
    }
    return 0;
}
