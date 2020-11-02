//
#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int i=0;
    int min=0;
    int number;
    int A[128];

    while(scanf("%d", &number) != EOF){
        A[i] = number;
        i++;
    }

    number = i;
    min = A[0];

    for(i=0; i<=number-1; i++){
        if(min > A[i+1]){
            min = A[i+1];
        }
    }

    printf("The min number is %d \n", min);

    return 0;
}
