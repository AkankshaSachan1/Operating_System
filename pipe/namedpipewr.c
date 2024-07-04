#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZE 500
char* buff;
int main()
{
    //char buff[MAXSIZE];
  
    int fd;

    buff=(char*)malloc(MAXSIZE*sizeof(char));
    if(buff==NULL){
        perror("memory not allocated\n");
        exit(EXIT_FAILURE);
    }

    if(mkfifo("namedpipe",S_IRWXU)==-1)
    {
        perror("Error in named pipe");
        exit(EXIT_FAILURE);
    }
    
    int fd1=open("namedpipe",O_WRONLY);
    if(fd1==-1)
    {
        perror("error opening named pipe");
        exit(EXIT_FAILURE);
    }
   
    fd=open("data.txt",O_RDWR,0777);
    if(fd==-1)
    {
        perror("Error oprning file\n");
        exit(EXIT_FAILURE);
    }
    int rd=read(fd,&buff,MAXSIZE);
    if(rd==-1)
    {
        perror("error writing into file");
        exit(EXIT_FAILURE);
    }
    int wr=write(fd1,&buff,MAXSIZE);
    if(wr==-1)
    {
        perror("error in writing into file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    close(fd1);
    free(buff);
    return 0;
}    