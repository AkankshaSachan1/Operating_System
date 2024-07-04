#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>

int count=0;
//int writer_count=0;

sem_t writer_sig,reader_sig;
int x=0;

void* writer(void *arg){
   
    int i = *(int*)arg;
printf("writer[%d] thread is waiting\n",i);
while(1){
       // sem_wait(&bin);
        sem_wait(&reader_sig);
        count++;
printf("writer[%d] thread done writing\n",i);
        for(int i=0;i<3;i++){
        sem_post(&writer_sig);
        }
       // sem_post(&bin);
        
}

}

void* reader(void* arg){
   int i = *(int*)arg;
   
    printf("reader[%d] thread is waiting\n",i);
    while(1){
        
      sem_wait(&writer_sig);  
  //  printf("count=%d\n",count);
printf("reader[%d] thread done reading\tcount=%d\n",i,count);
    ++x;
        if(x==3){
        sem_post(&reader_sig);
        x=0;
    }

    sleep(1);
}
free(arg);
}

int main(){
   
    pthread_t writer_thread[1],reader_thread[3];
    

    sem_init(&reader_sig,0,1);
    sem_init(&writer_sig,0,0);
   // sem_init(&bin,0,1);

    for(int i=0;i<=0;i++){
        int* a = malloc(sizeof(int));
        *a = i; 
      //  printf("writer thread_create\n");
    if(pthread_create(&writer_thread[i],NULL,(void*)writer,a)!=0){
        perror("writer thread not create\n");
        exit(EXIT_FAILURE);
    }
 //   usleep(100);
    }

    for(int j=0;j<3;j++){
      //  printf("reader thread_create\n");
    if(pthread_create(&reader_thread[j],NULL,(void*)reader,&j)!=0){
        perror("reader thread not create\n");
        exit(EXIT_FAILURE);
    }
      // usleep(100);
    }

    for(int i=0;i<1;i++){
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

    sem_destroy(&reader_sig);
    sem_destroy(&writer_sig);
    return 0;
}