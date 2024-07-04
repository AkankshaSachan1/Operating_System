#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZE 50
int main()
{
    char buff[MAXSIZE];
    char buff1[MAXSIZE];
    int fd;

    if((mkfifo("namedpipe",0777))==-1)
    {
        perror("Error in named pipe");
        exit(EXIT_FAILURE);
    }
    
        int fd1=open("namedpipe",O_RDWR);
        if(fd1==-1)
    {
        perror("error opening named pipe");
        exit(EXIT_FAILURE);
    }
   
    fd=open("data.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("Error oprning file\n");
        exit(EXIT_FAILURE);
    }
    int rd=read(fd,buff,MAXSIZE);
    if(rd==-1)
    {
        perror("error writing into file");
        exit(EXIT_FAILURE);
    }
    if(write(fd1,buff,MAXSIZE)==-1){
        perror("error in writing\n");
        exit(EXIT_FAILURE);
    }
    close(fd);
    close(fd1);
    return 0;
}    