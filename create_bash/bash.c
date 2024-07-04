#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

// int main(){
//     char cmd[10];
//     pid_t pid;
//     int fd;

//    printf("enter command\n");
//    fgets(cmd,10,stdin);
//     //write(fd,cmd,sizeof(cmd));
//     cmd[strlen(cmd)-1] ='\0';
//      pid = fork();
// if(pid==0){
//         char *ptr[]={cmd,NULL};
//         execvp(ptr[0],ptr);
//      }

// }
int main(){
    char *ch;
    char cmd[10];
    pid_t pid;
    int fd;

   printf("enter command\n");
   fgets(cmd,10,stdin);
    //write(fd,cmd,sizeof(cmd));
    cmd[strlen(cmd)-1] ='\0';
     pid = fork();
     printf("before exec:%d \t%d",getpid(),getppid());

if(pid==0){
        char *ptr[]={cmd,NULL};
        execvp(ptr[0],ptr);
             //printf("after exec:%d \t%d",getpid(),getppid());

     }
printf("after exec:%d \t%d",getpid(),getppid());
}


