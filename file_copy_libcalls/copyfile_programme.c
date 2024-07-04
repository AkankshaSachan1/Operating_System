#include<stdio.h>
#include<stdlib.h>
int main(){
FILE *fp1,*fp2;
char buff[2];
size_t src;
fp1 = fopen("intro.txt","r");
if(fp1==NULL){
    printf("FILE READ ERROR\n");
    exit(1);    
}
fp2 = fopen("file.txt","w");
if(fp2==NULL){
    printf("FILE open ERROR\n");
    exit(1);    
}

//src=fread(buff,1,sizeof(buff),fp1);
while((fread(buff,1,sizeof(buff),fp1))>0){
    
    fwrite(buff,1,sizeof(buff),fp2);
}

fclose(fp1);
fclose(fp2);
return 0;
}
