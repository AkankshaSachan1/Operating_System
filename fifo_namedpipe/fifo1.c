#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#define buff_SIZE 4096
int main(){
    char ch[buff_SIZE];
    char ch1[buff_SIZE];
    int fd;
    int file =open("data.txt",O_RDONLY,S_IRWXU);
    if(read(file,&ch1,buff_SIZE)==-1){
        perror("read from data file failed\n");
        exit(1);
    }
    fd =open("fifofile",O_WRONLY);
    if(fd==-1){
        perror("error in openning file\n");
    }
    if(write(fd,&ch1,buff_SIZE)==-1){
        perror("writng into fifo error");
    }
    
    // int src=write(fd,&ch,sizeof(ch));
    // if(src==-1){
    //     perror("writing in file error\n");
    //     exit(1);
    // }
    close(fd);
    printf("writing successfully\n");
    return 0;
}
