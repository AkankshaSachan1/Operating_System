#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int a,b;
int sum;
sem_t input_sem;
void *input()
{
         //sem_wait(&input_sem);
        printf("enter first number");
        scanf("%d",&a);
        printf("enter second number");
        scanf("%d",&b);
        sem_post(&input_sem);
       // pthread_exit(NULL);
        
    
}
void *process()
{
   
       sem_wait(&input_sem);
      
        sum=a+b;
         sem_post(&input_sem);
        printf("sum=%d\n",sum);
        
        pthread_exit(NULL);
    
    
}
int main()
{
    pthread_t thread1,thread2;
    if(sem_init(&input_sem,0,0)!=0)
    {
        perror("sem_init");
        exit(EXIT_FAILURE);
    }
   
    if(pthread_create(&thread1,NULL,input,NULL)!=0)
    {
        perror("thread1");
        exit(EXIT_FAILURE);
    }
    if(pthread_create(&thread2,NULL,process,NULL)!=0)
    {
        perror("thread2");
        exit(EXIT_FAILURE);
    }
    if(pthread_join(thread1,NULL)!=0)
    {
        perror("Join thread1");
        exit(EXIT_FAILURE);
    }
   if(pthread_join(thread2,NULL)!=0)
    {
        perror("Join thread2");
        exit(EXIT_FAILURE);
    }
    if(sem_destroy(&input_sem)!=0)
    {
        perror("sem destroy");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}