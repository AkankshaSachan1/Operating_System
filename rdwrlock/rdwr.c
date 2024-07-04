#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int count=0;
pthread_rwlock_t count_rwlock;
void *reader1(void *data)
{
    int z;
    printf("reader1:enter critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("reader1:inside critical section\n");
    z=count+10;
    printf("reader 1 %d\n",z);
    pthread_rwlock_unlock(&count_rwlock);
     printf("reader1:left critical section\n");
}

void *reader2(void *data)
{
    int x;
    printf("reader2:enter critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("reader2:inside critical section\n");
    x=count+40;
    printf("reader 2 %d\n",x);
    pthread_rwlock_unlock(&count_rwlock);
     printf("reader2:left critical section\n");
}

void *writer1(void *data)
{
    
    printf("writer 1:enter critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("writer 1:inside critical section\n");
   count++;
    printf("writer 1 %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);
     printf("writer 1:left critical section\n");
}
int main()
{
    pthread_t r1,r2,w1;
    pthread_rwlock_init(&count_rwlock,NULL);
    pthread_create(&r1,NULL,reader1,NULL);
    pthread_create(&r2,NULL,reader2,NULL);
    pthread_create(&w1,NULL,writer1,NULL);
    pthread_join(r1,NULL); 
    pthread_join(r2,NULL);
    pthread_join(w1,NULL);
    pthread_rwlock_destroy(&count_rwlock);
    return 0;
}