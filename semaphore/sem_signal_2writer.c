#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>

int count=0;
//int writer_count=0;

sem_t writer_sig,reader_sig[2];
int x=0;
int j=0;

void* writer(void *arg){
   
    int i = *(int*)arg;
printf("reader[%d] thread is waiting\n",j);
while(1){
        sem_wait(&reader_sig[j]);
        count++;
        j=(j==0?1:0);
printf("writer[%d] thread done writing\n",j);
        for(int i=0;i<3;i++){
        sem_post(&writer_sig);
        }
              
    }
}

void* reader(void* arg){
   int i = *(int*)arg;
   
    printf("writer[%d] thread is waiting\n",i);
    while(1){
      sem_wait(&writer_sig);  
printf("reader[%d] thread done reading\tcount=%d\n",i,count);
    ++x;
        if(x==3){
        sem_post(&reader_sig[j]);
        x=0;
    }

    sleep(1);
}
free(arg);
}

int main(){
   
    pthread_t writer_thread[2],reader_thread[3];
    

    sem_init(&reader_sig[0],0,1);
    sem_init(&reader_sig[1],0,0);
    sem_init(&writer_sig,0,0);
   

    for(int i=0;i<=1;i++){
        int* a = malloc(sizeof(int));
        *a = i; 
     
    if(pthread_create(&writer_thread[i],NULL,(void*)writer,a)!=0){
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

    sem_destroy(&reader_sig[0]);
    sem_destroy(&reader_sig[1]);
    sem_destroy(&writer_sig);
    return 0;
}