#include <stdio.h>
#include <stdlib.h>

#define SIZE 32 //總位元長度
#define Block 8 //間隔區塊大小

int main(void){

    int i = 0;              //Loop counter
    int DecNum, Ans;        //Calculus
    int counter = 0;        //Format
    int Bin[SIZE] = {0};    //Setting: Bin[SIZE] All of 0

    scanf("%d",&DecNum);    //input data
    //DecNum = 15;
    /*Calculus*/
    while (DecNum >= 1){
        Ans = DecNum % 2;
        DecNum /= 2;

        Bin[i] = Ans;   //Save to Bin[]
        i++;    //Loop

        // if(i>SIZE){
        //     printf("Error! Plz check the range of Loop i\n");
        //     return 0;
        // }
    }
    /*Output: Format*/
    for(i=SIZE-1; i>=0; i--){
        printf("%d", Bin[i]);

        counter ++;
        if(counter == Block && i > 0){  // i>2 is close the last "-"
            printf("-");
            counter = 0;
        }
    }
    printf("\n");
    
    return 0;
}

