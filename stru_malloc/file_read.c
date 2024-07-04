#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int fd1;
void * file_read(struct student *stu)
{
   fd1=open("new_data.txt",O_CREAT|O_RDWR);
   if(fd1==-1)
   {
    perror("Error in opening file");
    exit(EXIT_FAILURE);
   }
}