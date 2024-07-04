#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<mqueue.h>
#include<errno.h>
#include<string.h>
#define MAXSIZE 4095
char buff[MAXSIZE];
mqd_t mqd;
struct mq_attr attr;
int main()
{
    int fd,count=0;
    int priority;

    attr.mq_curmsgs=0;
    attr.mq_flags=0;
    attr.mq_maxmsg=1;
    attr.mq_msgsize=MAXSIZE;

    mqd=mq_open("/stdio_mq",O_CREAT|O_RDWR,0777,&attr);
    if(mqd==-1)
    {
        perror("Error opening file 3");
        exit(EXIT_FAILURE);
    }
    fd=open("/usr/include/stdio.h",O_RDONLY,0777);
    if(fd==-1)
    {
        perror("Error opening file 4");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<1;i++)
    {
        ssize_t rec=mq_receive(mqd,buff,MAXSIZE,&priority);
        printf("Received %ld bytes\n",rec);
        if(rec==-1)
        {
            perror("error receiving file");
            exit(EXIT_FAILURE);
        }
        for(int i=0;i<=strlen(buff);i++)
        {
            if(buff[i]=='s' ||buff[i]=='S')
            {
                count++;
            }
        }
    }
    printf("\n S comes %d time in file\n",count);
    mq_close(mqd);
    return 0;
}