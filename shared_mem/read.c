#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include <fcntl.h>

int *count=0;

int main(){
    int shm_fd;

    shm_fd = shm_open("/data",O_CREAT|O_RDWR,0777);

    if(shm_fd==-1){
        perror("error in shared memory\n");
        exit(EXIT_FAILURE);
    }

    ftruncate(shm_fd,sizeof(int));

    count = (int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);

        while(1){
            printf("%d\n",*count);
            sleep(1);
        }
        
         if (shm_unlink("/data") == -1) {
        perror("Error in shm_unlink\n");
        exit(EXIT_FAILURE);
    }
      munmap(count,sizeof(int));
        close(shm_fd);
        return 0;
}