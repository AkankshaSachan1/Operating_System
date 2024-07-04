#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int count=0;
pthread_mutex_t mutex_count;
void* dec_count(){
    printf("thread2 created\n");
    while(1){
        pthread_mutex_lock(&mutex_count);
        count--;
        printf("dec:%d\n",count);
        pthread_mutex_unlock(&mutex_count);

    }
}
void* inc_count(){
        printf("thread1 created\n");
        while(1){
        pthread_mutex_lock(&mutex_count);
        count++;
        printf("inc:%d\n",count);
         pthread_mutex_unlock(&mutex_count);
}
}

int main(){
    pid_t pid = fork();
    pthread_t thread1,thread2;
    pthread_mutex_init(&mutex_count,NULL);
    if(pid==-1){
        perror("fork failed\n");
        exit(1);
    }
    else if(pid>0){
        printf("parent is created\n");
        wait(NULL);
    }
    else if(pid==0){
        pthread_create(&thread1,NULL,(void*)inc_count,NULL);
        pthread_create(&thread2,NULL,(void*)dec_count,NULL);
        pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);
    }
        pthread_mutex_destroy(&mutex_count);   
}