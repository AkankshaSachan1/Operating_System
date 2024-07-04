#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>

int count=0;
//int writer_count=0;

sem_t sem;

void* writer(void *arg){
    int i = *(int*)arg;
printf("reader[%d] thread is waiting\n",i);
while(1){
        sem_wait(&sem);
        
        count++;
printf("writer[%d] thread done writing\n",i);
        sem_post(&sem);
        sleep(1);
}

}

void* reader(void* arg){
   int i = *(int*)arg;
   
    printf("writer[%d] thread is waiting\n",i);
    while(1){
      sem_wait(&sem);  
  //  printf("count=%d\n",count);
printf("reader[%d] thread done reading\tcount=%d\n",i,count);
    sem_post(&sem);
    sleep(1);
}
free(arg);
}

int main(){
   
    pthread_t writer_thread[2],reader_thread[3];
    

    sem_init(&sem,0,1);

    for(int i=0;i<2;i++){
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

    sem_destroy(&sem);
    return 0;
}