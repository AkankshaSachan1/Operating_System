//for seeing zombie child do command ps -al
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
int main(){
    pid_t pid = fork();

    if(pid > 0){
        printf("parent is created:\t pid=%d \t ppid=%d\n",getpid(),getppid());
        sleep(20);
        printf("after sleep: pid=%d\tppid=%d\n",getpid(),getppid());
    }
    else if(pid == 0){
        printf("\nchild is created: pid=%d\tppid=%d\n",getpid(),getppid());
        exit(0);
        printf("\nchild died");
    }
    else{
        perror("\nfork process failed");
        exit(1);
    }
    return 0;
}