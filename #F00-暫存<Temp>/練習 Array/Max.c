#include <stdio.h>

#define SIZE 5

int MaxNumber(int* Arr) {

    int Max = -1;
    
    for (int i = 0; i < SIZE-1; i++) {
        if(Max < Arr[i]) {
            Max = Arr[i];
        }
    }

    return Max;
}

int main(void){

    int Arr[5];
    
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &Arr[i]);
    }

    int MaxNum = MaxNumber(Arr);

    printf("Max: %d", MaxNum);

    return 0;
}