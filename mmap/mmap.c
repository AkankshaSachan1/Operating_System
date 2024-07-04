#include<stdio.h>
#include<stdlib.h>
//#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/wait.h>
int count =5;

int main(){
  //  pthread_t thread[2];
    pid_t id;
    
    

  int* sh_mem = (int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,-1,0);

  if(sh_mem==MAP_FAILED){
    perror("no mapping\n");
    exit(EXIT_FAILURE);
  }

    id=fork();

    sh_mem = 80;

    if(id==-1){
        perror("error fork\n");
        exit(EXIT_FAILURE);
    }

    else if(id>0){
        printf("parent created\n");
      // sleep(1);
        wait(NULL);
        printf("%d\n",sh_mem);
    }
    else if(id==0){
        printf("child created\n");
        sh_mem = 50;
       // count = 10;
        printf("%d\n",sh_mem);
    }



}