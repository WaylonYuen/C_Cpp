//title: find the Arr[] bigger number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){

    int holdIndex;
    int BigNumber = -1;

    int Arr[SIZE] = {0};

    srand(time(NULL));

    //Random
    for (int i = 0; i < SIZE; i++) {
        Arr[i] = rand();
        printf("Arr[%d] = %d\n", i, Arr[i]);
    }
    

    //find
    for(int i = 0; i < SIZE; i++){
        if(BigNumber < Arr[i]){
            BigNumber = Arr[i];
            holdIndex = i;
        }
    }

    printf("Big number: %d : Arr[%d]", BigNumber, holdIndex);

    return 0;
}