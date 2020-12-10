#include <stdio.h> 
#include <stdlib.h> 

#define N 5 

void Function(int i, int j, int key);

int counter;

int square[N+1][N+1] = {0}; 

int main(void) { 

    int i, j, key;
    counter = 0; 
    i = 0; //y
    j = (N+1) / 2;  //置中x

    Function(i,j,1);
    printf("\nCounter : %d\n",counter);
    return 0; 
} 

void Output(){
    int i,j;

    //output
    for(i = 1; i <= N; i++) {   counter++;
        for(j = 1; j <= N; j++){  counter++;
            printf("%2d ", square[i][j]);  counter++;
        }
        puts("");   counter++;
    } 
}

void Function(int i, int j, int key) {
    
    counter++;
    if(key > N*N){  
        Output();   //counter++;
    }else {
        //計算座標
        counter++;
        if((key % N) == 1) {    
            i++;                counter++;
        }
        else { 
            i--;    counter++;
            j--;    counter++;
        } 

        //置換
        counter++;
        if(i == 0){ 
            i = N;  counter++;
        }   

        counter++;
        if(j <= 0) {
            j = N;  counter++;

        }   
        square[i][j] = key; counter++;     //存值
        Function(i, j, key+1);  counter++;  //遞迴
    }
}
