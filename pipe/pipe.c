#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MAX_SIZE 4095
char buff [MAX_SIZE];
int main()
{
    int fd[2];
    pid_t pid;
    char rec_buff[MAX_SIZE];
    if(pipe(fd)<0);
    int fdr = open("/usr/include/stdio.h",O_RDONLY,0777);
    if(fdr==-1)
    {
        perror("Error Opening file");
        exit(EXIT_FAILURE);
    }
    pid=fork();
    if(pid<0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if(pid>0)
    {
        if(read(fdr,buff,MAX_SIZE)==-1)
        {
            perror("error in reading file");
            exit(EXIT_FAILURE);
        }
        if(write(fd[1],buff,MAX_SIZE)==-1)
        {
            perror("error in writing in file");
            exit(EXIT_FAILURE);
        }
    }

    if(pid==0)
    {
        int num;
        int count=0;
        if(read(fd[0],&rec_buff,MAX_SIZE)==-1)
        {
            perror("error in reading file p2");
            exit(EXIT_FAILURE);
        }
        for(int i=0;i<strlen(rec_buff);i++)
        {
            if(rec_buff[i]=='s' || rec_buff[i]=='S')
            count++;
        }
        printf("\n S comes %d times in stdio.h \n",count);
    }
    close(fd[0]);
    close(fd[1]);
    return 0;    
}