#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    pid_t pid = fork();

    if(pid>0){
        printf("parent created: pid=%d\tppid=%d\n",getpid(),getppid());
        exit(0);
        printf("after parent exit!: pid=%d\tppid=%d\n",getpid(),getppid());
    }
    else if(pid == 0){
        printf("child is created:pid=%d\tppid=%d\n",getpid(),getppid());
        sleep(20);
        printf("after sleep child: pid=%d\tppid=%d\n",getpid(),getppid());
    }
    else{
        perror("fork failed");
        exit(1);
    }
    return 0;
}