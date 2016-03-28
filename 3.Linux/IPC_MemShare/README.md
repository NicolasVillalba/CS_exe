#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>//sleep函数
#include<string.h>
#include<sys/select.h>



typedef struct {
    int lock;
    int noread;
    char buf[1024];
}chat, *pchat;



void lock(int* p)
{
    while(1)
    {
        if(*p == 0)
        {
            *p = 1;
            break;
        }
    }
}

void unlock(int *p)
{
    *p = 0;
}



int main(int argc, char* argv[])
{
    int shmid;//声明共享内存的id
    shmid = shmget((key_t)1235, 1<<10, IPC_CREAT|0600);//创建共享内存并且获得共享内存id,有iIPC_EXCL在重新创建相同的共享内存的时候会提示创建失败
    if(-1 == shmid)
    {
        perror("shmget");
        exit(-1);
    }
    pchat p;
    p = (pchat)shmat(shmid, NULL, 0);//链接共享内存
    if((pchat)-1 == p)
    {
        perror("shmat");
        return -1;
    }
    fd_set rdset;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;
    int ret;
    char buf[1024];
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(0, &rdset);
        ret = select(1, &rdset, NULL, NULL, &tv);
        if(ret > 0)
        {
            memset(buf, 0, sizeof(buf));
            read(0, buf, sizeof(buf));//读进来
            lock(&p->lock);//加锁
            strncpy(p->buf,buf, strlen(buf) - 1);
            p->noread = 2;
            unlock(&p->lock);
        }
        lock(&p->lock);
        if(p->noread == 1)
        {
            printf("%s\n", p->buf);
            p->noread = 0;
            memset(p->buf, 0, sizeof(p->buf));
        }
        unlock(&p->lock);
        usleep(5);
    }
    return 0;
}
