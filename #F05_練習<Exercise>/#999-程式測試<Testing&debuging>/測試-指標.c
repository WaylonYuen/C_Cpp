#include<stdio.h>
#include<stdlib.h>

int main(){

    int a = 10;
    int *ptr;

    ptr = &a;

    puts("get a Address:");
    printf("\t&a = %p\n", &a);
    printf("\tptr = %p\n", ptr);//ptr = &a

    puts("");

    puts("get a value:");
    printf("\ta = %d\n", a);// int a = 10
    printf("\t*ptr = %d\n", *ptr);

    puts("");

    puts("get ptr address:");
    printf("\t&ptr = %p\n", &ptr);

    return 0;
}