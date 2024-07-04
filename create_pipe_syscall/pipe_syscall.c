#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>
#include<string.h>
int main(){
    pid_t pid;
    int fd[2];
    char buff[]="HELLO CDAC COURSE EMBEDDED";
    char read_buff[27];
if(pipe(fd)<0){
    perror("error pipe creation");
    exit(1);
}
else {
    pid = fork();
    if(pid<0){
        perror("fork error");
        exit(1);
    }
    
    else if(pid>0){
        close(fd[0]);
        write(fd[1],buff,sizeof(buff));
        close(fd[1]);
        
    }
    else if(pid==0){
        close(fd[1]);
        read(fd[0],read_buff,sizeof(read_buff));
        close(fd[0]);
        printf("%s\n",read_buff);
    }
    
}

return 0;
}

