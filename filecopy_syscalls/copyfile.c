#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>
int main(){
    int fd1,fd2;
    char buff[1];
    fd1 = open("intro.txt",O_RDONLY,S_IRWXU);
    if(fd1 ==-1){
        perror("error fd1");
        exit(1);
    }
    fd2 = open("data.txt",O_WRONLY | O_CREAT,S_IRWXU);
    if(fd2==-1){
        perror("fd2 error");
        exit(1);
    }
while(read(fd1,buff,sizeof(buff))>0){
    write(fd2,buff,sizeof(buff));
}
close(fd1);
close(fd2);
return 0;
}