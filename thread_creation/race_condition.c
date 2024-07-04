#include<pthread.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int count=0;
void* threadinc(int arg[]){
    printf("1st thread created\n");
  while(1){
    count++;
    printf("inc =%d\n",count);
  }
    printf("1st thread terminated\n");
}
void* threaddec(int arg[]){
     printf("2nd thread created\n");
     while(1){
    count--;
    printf("dec=%d\n",count);
  }
    printf("2nd thread terminated\n");
}
int main(){
    pthread_t thread;

     pthread_create(&thread,NULL,threadinc,&count);
     pthread_create(&thread,NULL,threaddec,&count);
     pthread_join(thread,NULL);
     pthread_join(thread,NULL);
    return 0;
}    

