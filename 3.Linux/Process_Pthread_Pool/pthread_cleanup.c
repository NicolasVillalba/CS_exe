#include<stdio.h>
#include<pthread.h>

void CleanFunc(void *pArg)
{
    printf("CleanFunc(%d)\n",(int)pArg);
}

void *ThreadFunc(void *pArg)
{
    pthread_cleanup_push(CleanFunc, (void*)1);
    pthread_cleanup_push(CleanFunc, (void*)2);
    sleep(2);
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
}


int main()
{
     pthread_t pth;
     pthread_create(&pth, NULL, ThreadFunc, (void *)2);
     pthread_join(pth, NULL);
     return 0;
}



