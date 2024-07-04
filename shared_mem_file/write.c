#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include <fcntl.h>

#define size 20


int main(){

  char* buff = (char*)malloc(size*sizeof(char));
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

     int fd = open("file.txt",O_RDWR);
     if(fd==-1){
        perror("error in open file\n");
        exit(EXIT_FAILURE);
     }

     if(read(fd,buff,size)==-1){
        perror("error in reading file\n");
        exit(EXIT_FAILURE);
    }

    if(write(shm_fd,buff,size*sizeof(char))==-1){
        perror("error in writing file\n");
        exit(EXIT_FAILURE);
       }

   // buff = (char*)mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);

    close(shm_fd);
    close(fd);
    free(buff);

}