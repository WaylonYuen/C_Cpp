#include<stdio.h>

    typedef struct student{
        char name[20];
        int age;
        int studentID[10];
    }stu;

int main(){

    stu stu1;

    stu1.age = 12;

    printf("%d", stu1.age);

    return 0;
}