#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

#define size 10
pthread_mutexattr_t student;
struct student{
        char name[size];
        int roll_no;
        char course[size];
}stu[1];
int i=0;
char read_buff[4096];
int num;
void* file_write(void *arg){
    int fd;
    struct student *stu=(struct student*)arg;
    fd = open("data.txt",O_CREAT|O_RDWR,S_IRWXU);
    printf("file opened\n");
    if(fd==-1){
        perror("error opening file\n");
        exit(1);
    }
    for(i=0;i<num;i++)
    {
        dprintf(fd,"Name=%s\nRoll No.=%d\nCourse=%s\n",stu[i].name,stu[i].roll_no,stu[i].course);
    }
    printf("written successfully\n");
    
    for(i=0;i<num;i++)
    {
        printf("%s\n%d\n%s\n",stu[i].name,stu[i].roll_no,stu[i].course);
    }
   printf("child terminated\n");
    close(fd);
}
void *file_read(void *arg)
{
    int fd1,fd2;
    fd1=open("data.txt",O_RDONLY,S_IRWXU);
    if(fd1==-1)
    {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }
    int src=read(fd1,read_buff,sizeof(read_buff))
}

int main(){
     
     
     printf("enter the no of student\n");
     scanf("%d",&num);
     struct student *stu= (struct student*)malloc(num*sizeof(struct student));
    pthread_t thread1,thread2;
    if(stu==NULL){
        perror("error in memory allocation");
        exit(1);
    }
      
    // printf("enter student details\n");
    // struct student stu = {"sk",12,"desd"};
     
       while(i<num){ 
        printf("enter name of student\n");
        scanf("%s",stu[i].name);
        printf("enter roll_no of student\n");
        scanf("%d",&stu[i].roll_no);
        printf("enter course name\n");
        scanf("%s",stu[i].course);
        i++;
    }

     __pid_t pid=fork();

     if(pid==-1)
     {
        perror("fork failed");
        exit(EXIT_FAILURE);
     }
     if(pid>0)
     {
        printf("Parent Created");
        wait(NULL);
     }
     else if(pid==0)
     {
           
           pthread_mutex_init(&student,NULL);
        pthread_create(&thread1,NULL,(void*)file_write,stu);
        pthread_join(thread1,NULL);
        //pthread_create(&thread2,NULL,file_read,stu);
        //pthread_join(thread2,NULL);
        pthread_mutex_destroy(&student);
     }
     free(stu);
     return 0;
}
