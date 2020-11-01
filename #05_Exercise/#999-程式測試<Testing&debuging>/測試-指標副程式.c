
//陣列指標 的傳參練習

#include<stdio.h>
#include<stdlib.h>

int pointer(int* A, int *SIZE){
    int i;
    for(i=0; i<*SIZE; i++){
        A[i] = i;
        printf("%d ", A[i]);
    }
    

    return A[0];
}

int main(){
    int size=5;
    int A[size];

    A[0] = pointer(&A[0], &size);

    puts("\n");
    int i;
    for(i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    puts("\n");

    int *ptr = A;
    int hold = *(ptr + 3);

    printf("\nptr+1: %d\n", hold);

    return 0;
}