#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include "header.h"
#define size 2
struct student{
        char name[size];
        int roll_no;
        char course[size];
};
struct student *stu;
void* file_write(void *arg)
{
   
   int fd;
   fd=open("ata.txt",O_CREAT|O_RDWR,S_IRWXU);
   if(fd==-1)
   {
      perror("File opening error");
      exit(EXIT_FAILURE);
   }
   for(int i=0;i<num;i++)
}
int main(){
     int i=0;
    pthread_t thread1,thread2;
        printf("enter student details\n");
       while(i<size){
        printf("enter name of student\n");
        scanf("%c\n",stu->name[i]);
        printf("enter roll_no of student\n");
        scanf("%d\n",&stu->roll_no);
        printf("enter course name\n");
        scanf("%c\n",stu->course[i]);
        i++;
    }
     stu = (struct student*)malloc(sizeof(struct student));
     __pid_t pid=fork();

     if(pid==-1)
     {
        perror("fork failed");
        exit(EXIT_FAILURE);
     }
     if(pid>0)
     {
        printf("Parent Created");
     }
     else if(pid==0)
     {
        pthread_create(&thread1,NULL,(void*)file_write,&stu);
        pthread_join(thread1,NULL);
        //pthread_create(&thread2,NULL,file_read,&stu);
        //pthread_join(thread2,NULL);
     }
}
