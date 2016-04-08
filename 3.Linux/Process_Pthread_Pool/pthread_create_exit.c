#include<stdio.h>
#include<pthread.h>

void *func(void *pArg)
{
    int i = 0;
    for(; i < 10; i++)
    {
        printf("Hi, I am a child pthread, arg is %d\n", (int)pArg);
        sleep(1);
    }
    pthread_exit(NULL);
}


int main()
{
    pthread_t pth;
    pthread_create(&pth, NULL, func, (void *)123);
    int i = 0;
    for(; i < 10; i++)
    {
        printf("Hi, I am main pthread, child id is %x\n", pth);
    }
    return 0;
}
