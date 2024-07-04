#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<mqueue.h>
#include<errno.h>
#define MAXSIZE 4095
char buff[MAXSIZE];
mqd_t mqd;
struct mq_attr attr;
int main()
{
    int fd;
    attr.mq_curmsgs=0;
    attr.mq_flags=0;
    attr.mq_maxmsg=1;
    attr.mq_msgsize=MAXSIZE;

    mqd=mq_open("/stdio_mq",O_CREAT|O_RDWR,0777,&attr);
    if(mqd==-1)
    {
        perror("Message queue not created");
        exit(EXIT_FAILURE);
    }
     fd=open("/usr/include/stdio.h",O_RDONLY,0777);
    if(fd==-1)
    {
        perror("file no opened 1");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<1;i++)
    {
        ssize_t sender =read(fd,buff,MAXSIZE);
        if(sender==-1)
        {
            perror("file not opened 2");
            exit(EXIT_FAILURE);
        }
        if(mq_send(mqd,(const char *)&buff,MAXSIZE,0)==-1)
        {
            perror("Error in sending file");
            exit(EXIT_FAILURE);
        }
        printf("File sent successfully.total size %ld\n",sender);
    }
    mq_close(mqd);
    return 0;
}