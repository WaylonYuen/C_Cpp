#include <stdio.h> 
#include <stdlib.h> 

#define N 5

int counter;

void Function(int i, int j, int key, int Output[][N+1]) {

    counter++;
    if(key > N*N) { 
        
        for(i = 1; i <= N; i++) { 
            counter++;
            for(j = 1; j <= N; j++)  {
                counter++;
                printf("%2d ", Output[i][j]);   counter++;
            }
            puts("");           counter++;
        } 
    } else {
                                counter++;
        if((key % N) == 1) {    
            i++;                counter++;
        }
        else { 
            i--;                counter++;
            j--;                counter++;
        } 
                                counter++;
        if(i == 0) {            
            i = N;              counter++;
        } 
                                counter++;
        if(j <= 0) {            
            j = N;              counter++;
        } 

        Output[i][j] = key;     counter++;

        counter++;
        Function(i, j, key+1, Output);  //遞迴
    }
}

int main(void) { 
    int square[N+1][N+1] = {0}; 
    counter = 0;
    Function(0, (N+1) / 2, 1, square);
    printf("\nCounter : %d\n", counter);
    return 0; 
} 