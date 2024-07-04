#include<pthread.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
# define size 5
int num[size];
void* threadsum(int arg[]){
    printf(" thread created\n");
    int i =0;
    int sum=0;
    while(i<size){
    sum += arg[i];
    i++;
    } 
 printf("%d\n",sum);
    printf("thread terminated");
}
int main(){
    printf("enter num:");
    for(int i=0;i<size;i++){
    scanf("%d",&num[i]);
    }
    pthread_t thread;
   // pthread_t threads[2];
     pthread_create(&thread,NULL,(void*)threadsum,&num);
     pthread_create(&thread,NULL,(void*)threadsum,&num);
//     for(j=0;j<2;j++){
//    pthread_create(&threads[j],NULL,(void*)threadsum,&num);
pthread_join(thread,NULL);
pthread_join(thread,NULL);
//     }
    return 0;
}