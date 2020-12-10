//
#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int i=0;
    int max=0;
    int number;
    int A[128];

    while(scanf("%d", &number) != EOF){
        A[i] = number;
        i++;
    }

    number = i;
    max = A[0];

    for(i=0; i<=number-1; i++){
        if(max < A[i+1]){
            max = A[i+1];
        }
    }

    printf("The max number is %d \n", max);

    return 0;
}
