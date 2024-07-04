#include<stdio.h>
#include"arith.h"
int main(){
    int choice,a,b;
   printf("enter two numbers\n");
   scanf("%d\n%d",&a,&b);
    printf("what to do\n");
    printf("enter your choice/n1.do the sum/n2.do sub/n3.do mul/n4.do doob mar\n");
    scanf("%d",&choice);
    math(a,b,choice);
   
    return 0;
}