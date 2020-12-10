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
    int Ans[10][100] = {-1};
    int Counter[10] = {0};

    //random
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        int num = (rand() % 999);
        if(isChekinPass(i, Arr, num)) { 
            Arr[i] = num;
        } else {
            i--;
        }
    }

    //Group
    for (int i = 0; i < SIZE; i++) { 
        //printf("Test\n");
        switch (Arr[i] % 10) {
            case 0:
                Ans[0][Counter[0]++] = Arr[i];
                break;

            case 1:
                Ans[1][Counter[1]++] = Arr[i];
                break;

            case 2:
                Ans[2][Counter[2]++] = Arr[i];
                break;

            case 3:
                Ans[3][Counter[3]++] = Arr[i];
                break;

            case 4:
                Ans[4][Counter[4]++] = Arr[i];
                break;

            case 5:
                Ans[5][Counter[5]++] = Arr[i];
                break;

            case 6:
                Ans[6][Counter[6]++] = Arr[i];
                break;

            case 7:
                Ans[7][Counter[7]++] = Arr[i];
                break;

            case 8:
                Ans[8][Counter[8]++] = Arr[i];
                break;

            case 9:
                Ans[9][Counter[9]++] = Arr[i];
                break;
            
            default:
                printf("Error\n");
                break;
        }

    }

    //Sort
    int temp = 0;
    for (int k = 0; k < 10; k++) {

        //每個群組 Sort
        for (int i = 0; i < Counter[k]; i++) {
            for (int j = 0; j < Counter[k] - 1; j++) {
                if(Ans[k][j] > Ans[k][j+1]) {
                    SWAP(Ans[k][j], Ans[k][j+1], temp);
                }
            }
        }
    }

    //Show
    for (int i = 0; i < 10; i++) {

        printf("\n第%d群<位數%d>:\n", i, i);
        for (int j = 0; j < 100; j++) {

            if(Counter[i] == j) {
                break;
            }

            printf("%d ", Ans[i][j]);
        }
        puts("");
    }
    

    return 0;
}