#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int *count=0;
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
        *count=(*count)+1;
        sleep(1);
    }
    printf("procces ended");
    return 0;
    
}
