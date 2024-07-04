#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

struct students{
    char name[10];
    int roll_no;
    float marks;
};

void student_data(void* stud){
    printf("%s\t%d\t%f",stud.name,)
}

int main(){
    int students_num;
    int i=0;
    printf("enter the no.of students\n");
    scanf("%d",students_num);
    struct students *stud;
    stud= (struct students*)malloc(students_num*sizeof(struct students));
    printf("enter students details");
    while(i<students_num){
        printf("entre the name of student\n");
        scanf("%s",stud[i].name);
        printf("entre the roll_no of student\n");
        scanf("%d",&stud[i].roll_no);
        printf("entre the marks of student\n");
        scanf("%f",&stud[i].marks);
        i++;
    }
    struct array *arr

    students_data(&stud);
free(stud);
return 0;
}