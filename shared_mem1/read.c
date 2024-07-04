#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int *count=NULL;
int main()
{
    int shmfd;
    shmfd =shm_open("/datashm",O_CREAT|O_RDWR,0777);
    if(shmfd==-1)
    {
        perror("shm_open:");
        exit(EXIT_FAILURE);
    }
    ftruncate(shmfd,sizeof(int));
    count =(int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shmfd,0);
    while(1)
    {
        printf("%d\n",(*count));
        sleep(1);
    }
    
    return 0;
}