#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#define buff_SIZE 4096

int main(){
    char ch[buff_SIZE];
    int fd,fd1;
    if(mkfifo("fifofile", S_IRUSR | S_IWUSR)==-1){
                perror("error in fifo file\n");
                exit(1);
    }
    fd =open("fifofile",O_RDONLY);
    if(fd==-1){
        perror("error in openning file");
    }
    fd1=open("newdata.txt",O_CREAT|O_WRONLY,S_IRWXU);
    if(fd1==-1){
        perror("error open newdata.txt\n");
    }
    printf("reading from file\n");
    int des= read(fd,&ch,buff_SIZE);
    if(des==-1){
        perror("error in reading\n");
        exit(1);
    }
    if(write(fd1,&ch,buff_SIZE)==-1){
        perror("writing into newdata.txt failed");
        exit(EXIT_FAILURE);
    }
    close(fd);
    close(fd1);
 //   printf("%s\n",ch);
    return 0;
}
