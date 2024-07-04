#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>

int count=0;
pthread_rwlock_t rwlock;

void *write_1()
{
    while(1)
    {
        pthread_rwlock_rwlock(&rwlock);
        printf("write 1:locked\n");
        count++;
        sleep(2);
        pthread_rwlock_unlock(&rwlock);
        printf("write 1:unlocked\n");
    }
}

void *write_2()
{
    while(1)
    {
        pthread_rwlock_rwlock(&rwlock);
        printf("write 2:locked\n");
        count++;
        sleep(4);
        pthread_rwlock_unlock(&rwlock);
        printf("write 2:unlocked\n");
    }
}



int main(){
    pthread_t rd1,rd2,wr1,wr2;

    pthread_rwlock_init(&rwlock,NULL);
    pthread_create(&wr1,NULL,write_1,NULL);
    pthread_create(&wr2,NULL,write_2,NULL);
    pthread_create(&rd1,NULL,read_1,NULL);
    pthread_create(&rd2,NULL,read_2,NULL);
    pthread_join(rd1,NULL);
    pthread_join(rd2,NULL);
    pthread_join(wr1,NULL);
    pthread_join(wr2,NULL);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}