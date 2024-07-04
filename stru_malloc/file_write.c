#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int fd;
void* file_write(struct student *stu){
    fd = open("data.txt",O_RDWR);
    if(fd==-1){
        perror("error opening file");
        exit(1);
    }
    int src = write(fd,stu,sizeof(struct student *));
    if(src==-1){
        perror("error in writing into the file");
        exit(1);
    }
    close(fd);
}