#include<stdio.h>


void coor(int counterB[10][10]){
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            printf("%d ", counterB[i][j]);
        }
        puts("\n");
    }
}

int main(){

    int i,j;
    int counterA[100];
    int counterB[10][10];

    puts("\n\n");

/*清0*/
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            counterB[i][j] = 0;
            printf("%d ", counterB[i][j]);
        }
        puts("\n");
    }
    
/*input*/
    int x,y;
    scanf("%d%d", &x, &y);
/*處理*/    
    counterB[x][y] = 1;

/*output*/
    coor(counterB);

    return 0;
}

