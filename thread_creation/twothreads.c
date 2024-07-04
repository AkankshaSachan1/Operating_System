#include<pthread.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
# define size 5
int num[size];
void* threadsum(int arg[]){
    printf("1st thread created\n");
    int i =0;
    int sum=0;
    while(i<size){
    sum += arg[i];
    i++;
    } 
 printf("%d\n",sum);
    printf("1st thread terminated\n");
}
void* threadsub(int arg[]){
     printf("2nd thread created\n");
    int i =0;
    int diff=arg[0];
    while(i<size){
    diff -= arg[i+1];
    i++;
    } 
     printf("%d\n",diff);
    printf("2nd thread terminated\n");
}
int main(){
    printf("enter num:");
    for(int i=0;i<size;i++){
    scanf("%d",&num[i]);
    }
    pthread_t thread;
   // pthread_t threads[2];
     pthread_create(&thread,NULL,(void*)threadsum,&num);
     pthread_join(thread,NULL);
     pthread_create(&thread,NULL,(void*)threadsub,&num);
//     for(j=0;j<2;j++){
//    pthread_create(&threads[j],NULL,(void*)threadsum,&num);

pthread_join(thread,NULL);
//     }
    return 0;
}    
