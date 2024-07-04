#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#define MSG_SIZE 128
struct mq_attr attr;

mqd_t mqd;
int main()
{
    attr.mq_maxmsg=5;
    attr.mq_msgsize=MSG_SIZE;
    attr.mq_curmsgs=0;
    attr.mq_flags=0;
    mqd=mq_open("/data",O_CREAT|O_RDWR,0777,&attr);
    if(mqd==-1)
    {
        perror("Mq open");
        exit(EXIT_FAILURE);
    }
    if(mq_send(mqd,"AKANKSHA",8,0)==-1)
    {
        perror("Sending error");
        exit(EXIT_FAILURE);
    }
    return 0;
}