#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;//定义一个锁

void *pthfunc(void *args)
{
    pthread_mutex_lock(&lock);//加锁
 //   pthread_mutex_lock(&lock);
    pthread_mutex_trylock(&lock);
    printf("hello\n");
    sleep(1);
    pthread_exit(NULL);
}


main()
{
     pthread_t pth = 0;
     pthread_mutex_init(&lock, NULL);
     pthread_create(&pth, NULL, pthfunc, NULL);
     pthread_join(pth, NULL);
     pthread_mutex_destroy(&lock);
}
