#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

#define bool int
#define true 1
#define false 0

bool isChekinPass(int len, int *num, int randomNum) {

    for (int i = 0; i < len; i++) {
        if(num[i] == randomNum) {
            return false;
        }
    }
    
    return true;
}

int main(void) {

    int Arr[SIZE];
    int Counter[50];
    int Ans[50];

    //random
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        int num = (rand() % 100 + 1);
        if(isChekinPass(i, Arr, num)) { 
            Arr[i] = num;
        } else {
            i--;
        }
    }

    for (int i = 0; i < 50; i++) {
        Ans[i] = Arr[i];
    }
    

    //Sort
    int temp = 0;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50 - 1; j++) {
            if(Ans[j] > Ans[j+1]) {
                SWAP(Ans[j], Ans[j+1], temp);
            }
        }
    }
    
    //Show
    for (int i = 0; i < 50; i++) {

        if(i % 5 == 0) {
            printf("\n");
        }

        printf("%3d ", Ans[i]);
    }

    

    return 0;
}