#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
 #include <unistd.h>
sem_t s;
void *process(void *data)
{
    int n=*(int *)data;
    sem_wait(&s);
    printf("thread received data\n");
    sleep(1);
    sem_post(&s);
    printf("thread finished\n");
}
int main()
{
    sem_init(&s,0,1);
    int num;
    printf("enter number of threads");
    scanf("%d",&num);
    pthread_t thread[num];
    for(int i=0;i<num;i++)
    {
        pthread_create(&thread[i],NULL,process,&i);
    }
    for(int i=0;i<num;i++)
    {
        pthread_join(thread[i],NULL);
    }
    return 0;
}