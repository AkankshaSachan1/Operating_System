#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>           
#include <sys/stat.h>        
#include <mqueue.h>
#define SIZE 128

struct mq_attr attr;
mqd_t mqd;
int main()
{
  attr.mq_curmsgs=0;
  attr.mq_flags=0;
  attr.mq_maxmsg=0;
  attr.mq_msgsize=SIZE;

  mqd =mq_open("/data",O_CREAT|O_RDWR,0777,&attr);
  if(mqd==-1)
  {
    perror("mopen error");
    exit(EXIT_FAILURE);
  }
  mq_send(mqd,"Akanksha",8,0);
  mq_close(mqd);
  return 0;
}