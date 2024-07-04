#include<stdio.h>
#include<string.h>
int main(){
    char *str;
    printf("enter string");
    // for(int i=0;str[i]!='\n';i++){
    //         scanf("%c ",&str[i]);
    // }
   int n = scanf("%m[a-z]", &str);
if(n==1){
    scanf("%s ", &str);
    char newstr[50];
   // char *ptr = str;
    char *ptr1 = newstr;
   while(*str!='\0' ){
        // if(*ptr == '\0'){
        //      *ptr1++;
        //  }
       *ptr1++ = *str++ ;
    }
  *ptr1='\0';
    printf("\n%s",newstr);
}
    return 0;
}
