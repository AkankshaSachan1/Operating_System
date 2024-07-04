#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>

int count=0;
//int writer_count=0;
pthread_rwlock_t rwlock;
sem_t rd_signal,wr_signal;


void* writer(void *arg){
    int i = *(int*)arg;
printf("reader[%d] thread is waiting\n",i);
while(1){
   sem_wait(&wr_signal);
    pthread_rwlock_wrlock(&rwlock);
        count++;

printf("writer[%d] thread done writing\n",i);

       pthread_rwlock_unlock(&rwlock);
       for(int i=0;i<3;i++){
        sem_post(&rd_signal);
        }
      // sem_post(&rd_signal);
    
    }
}

void* reader(void* arg){
   int i = *(int*)arg;
   
    printf("writer[%d] thread is waiting\n",i);
    while(1){
     sem_wait(&rd_signal);
     pthread_rwlock_rdlock(&rwlock);
printf("reader[%d] thread done reading\tcount=%d\n",i,count);
     sleep(1);
    
     pthread_rwlock_unlock(&rwlock);
 sem_post(&wr_signal);
    }
}

int main(){
   
    pthread_t writer_thread[2],reader_thread[3];
    pthread_rwlock_init(&rwlock,NULL);
    sem_init(&rd_signal,0,1);
    sem_init(&wr_signal,0,0);

    for(int i=0;i<2;i++){
      
    if(pthread_create(&writer_thread[i],NULL,(void*)writer,&i)!=0){
        perror("writer thread not create\n");
        exit(EXIT_FAILURE);
    }
 
    }

    for(int j=0;j<3;j++){
     
    if(pthread_create(&reader_thread[j],NULL,(void*)reader,&j)!=0){
        perror("reader thread not create\n");
        exit(EXIT_FAILURE);
    }
      
    }

    for(int i=0;i<=1;i++){
    if(pthread_join(writer_thread[i],NULL)!=0){
        perror("writer thread join failed\n");
        exit(EXIT_FAILURE);
    }
    }
    for(int i=0;i<3;i++){
    if(pthread_join(reader_thread[i],NULL)!=0){
        perror("reader thread join failed\n");
        exit(EXIT_FAILURE);
    }
    }
   pthread_rwlock_destroy(&rwlock);
   sem_destroy(&rd_signal);
   sem_destroy(&wr_signal);
    
    return 0;
}