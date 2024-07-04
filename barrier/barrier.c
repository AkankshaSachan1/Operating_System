#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_barrier_t test;
int count=0;
int i=1;
void *w1()
{
    printf("before\n");
    sleep(2);
    pthread_barrier_wait(&test);
    count++;
    printf("writing 1:%d at %d",count,i);
}
void *w2()
{
    printf("before\n");
    sleep(2);
    pthread_barrier_wait(&test);
    count++;
    printf("writing2 :%d at %d",count,i);
}
void *r1()
{
    printf("before\n");
    sleep(3);
    pthread_barrier_wait(&test);
   
    printf("reading 1 :%d at %d",count,i);
}
void *r2()
{
    printf("before\n");
    sleep(6);
    pthread_barrier_wait(&test);
   
    printf("reading 2:%d at %d",count,i);
}
void *r3()
{
    printf("before\n");
    sleep(7);
    pthread_barrier_wait(&test);
   
    printf("reading 3:%d at %d",count,i);
}
int main()
{
    pthread_t wr1,wr2,rd1,rd2,rd3;
    pthread_barrier_init(&test,NULL,2);

    pthread_create(&wr1,NULL,w1,NULL);
    pthread_create(&wr2,NULL,w2,NULL);
    pthread_create(&rd1,NULL,r1,NULL);
    pthread_create(&rd2,NULL,r2,NULL);
    pthread_create(&rd3,NULL,r3,NULL);

    pthread_join(wr1,NULL);
    pthread_join(wr2,NULL);
    pthread_join(rd1,NULL);
    pthread_join(rd2,NULL);
    pthread_join(rd3,NULL);

    pthread_barrier_destroy(&test);
    return 0;
}