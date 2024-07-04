#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include <fcntl.h>

#define size 20
char* buff;
int main(){
   
   buff = (char*)malloc(size*sizeof(char));
    if(buff==NULL){
        perror("memory not allocated\n");
        exit(EXIT_FAILURE);
    }

   int shm_fd = shm_open("/data",O_CREAT|O_RDWR,0777);

    if(shm_fd==-1){
        perror("error in shared memory\n");
        exit(EXIT_FAILURE);
    }

    ftruncate(shm_fd,size*sizeof(char));

    buff = (char*)mmap(NULL,size*sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
    if(buff==MAP_FAILED){
        perror("error in mmap\n");
        exit(EXIT_FAILURE);
    }

     printf("%s\n",buff);
    // for(int i=0;i<size;i++){

      
    // }
        if(shm_unlink("/data")==-1){
            perror("error in shmlink\n");
            exit(EXIT_FAILURE);
        }
    //close(shm_fd);
  
}