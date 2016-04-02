#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//接力跑
pthread_mutex_t mutex1;
pthread_cond_t cond1;
void* tfunc(void *arg){
    printf("I'm the player %d\n",(int)arg);
    int i;
    pthread_mutex_lock(&mutex1);
    printf("wait\n");
    pthread_cond_wait(&cond1,&mutex1);//timedwait
    printf("Player%d get it!\n",(int)arg);
    for(i=1000;i>0;i--);
    printf("I passed it!\n");
    sleep(3);
    pthread_mutex_unlock(&mutex1);
    printf("Go ahead!\n");
}
int main(){
    int ret;
    pthread_mutex_init(&mutex1,NULL);
    pthread_cond_init(&cond1,NULL);
    pthread_t pth[4];
    int i;
    for(i=0;i<4;i++){
        ret=pthread_create(&pth[i],NULL,tfunc,(void*)i);
        if(ret!=0){
            printf("Not a team!\n");
            return -1;
        }
    }
    sleep(1);
    printf("Let's begin!\n");
    for(i=0;i<4;i++){
        pthread_cond_signal(&cond1);
  }
    //pthread_cond_broadcast(&cond1);
    for(i=0;i<4;i++){
        pthread_join(pth[i],NULL);
    }
    printf("Over\n");
    pthread_mutex_destroy(&mutex1);
    pthread_cond_destroy(&cond1);
    return 0;
}

