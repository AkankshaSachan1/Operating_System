#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int count=0;
sem_t sm_count;
void *inc(void *arg)
{
    while(1)
    {
       sem_wait(&sm_count);
        count++;
        printf("Inc=%d\n",count);
       sem_post(&sm_count);
    }
}
void *dec(void* arg)
{
    while(1)
    {
    sem_wait(&sm_count);
    count--;
    printf("dec=%d\n",count);
    sem_post(&sm_count);
    }
}
int main()
{
    pthread_t thread1,thread2;
    sem_init(&sm_count,0,1);
    pthread_create(&thread2,NULL,inc,NULL);
    pthread_create(&thread1,NULL,dec,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    sem_destroy(&sm_count);
    return 0;

}