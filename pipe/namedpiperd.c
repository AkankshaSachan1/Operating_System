#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZE 50
char* buff;
int main()
{
   // char buff[MAXSIZE];
   buff = (char*)malloc(MAXSIZE*sizeof(char));
   if(buff==NULL){
    perror("error in allocating memory\n");
    exit(EXIT_FAILURE);
   }
    int fd,fd1;
    fd1=open("namedpipe",O_RDWR);
    if(fd1==-1)
    {
        perror("error opening named pipe");
        exit(EXIT_FAILURE);
    }
    fd=read(fd1,buff,MAXSIZE);
    if(fd==-1)
    {
        perror("error reading file\n");
        exit(EXIT_FAILURE);
    }
    int count=0;

    printf("%s\n",buff);

    

    for(int i=0;i<MAXSIZE;i++)
    {
        if(buff[i]=='s' || buff[i]=='S')
        {
            count++;
        }
    }
    printf("total S =%d\n",count);
    close(fd);
    free(buff);
    return 0;
}