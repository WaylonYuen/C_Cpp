#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>

int main(){

    pid_t pid;

    pid = fork();

    if(pid < 0){
        perror("Error\n");
        exit(0);
    }
    else if(pid == 0){
        printf("子行程\n");
    }
    else{
        printf("父行程\n");
    }
    puts("End of fork()");

    printf("主程式\n\n");

    return 0;
}