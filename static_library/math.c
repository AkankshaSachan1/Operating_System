#include<stdio.h>
#include"arith.h"
void math(int a,int b,int choice){
    switch(choice){
        case 1:printf("sum is res=%d",sum(a,b));
            break;
        case 2:printf("sub is res=%d",sub(a,b));
            break;
        case 3:printf("mult is res=%d",mul(a,b));
            break;
        case 4: printf("-----------");
            break;
    }  
}