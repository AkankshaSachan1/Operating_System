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
    char buff[MSG_SIZE];
    int priority;

    attr.mq_curmsgs=0;
    attr.mq_flags=0;
    attr.mq_maxmsg=5;
    attr.mq_msgsize=MSG_SIZE;

    mqd=mq_open("/data",O_CREAT|O_RDWR,0777,&attr);
    if(mqd==-1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    mq_receive(mqd,buff,MSG_SIZE,&priority);
    printf("Message received=%s\n",buff);
    mq_close(mqd);
    return 0;
}