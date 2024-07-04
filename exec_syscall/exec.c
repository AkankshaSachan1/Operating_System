#include<stdio.h>
#include<string.h>
#include <unistd.h>
char new(char *ch){
    
    char ch1[]="cdac";
    *ch = ch1;
}
// int main(){
//     char ch[]="hyderbad";
//     int pid = fork();
//     if(pid==-1){
//         perror("error fork");
//     }
//     else if(pid>0){
//     printf("%s\n",ch);
//     }
//     else if(pid==0){
//     execl(new(&ch),ch,NULL);
//     }
//     return 0;
    
// }