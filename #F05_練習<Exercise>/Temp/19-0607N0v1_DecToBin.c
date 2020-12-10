// 編號：19-0607N0v1_DtB.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 * )
// 題目：十進位 轉 二進位

// 時間：NULL ( 不限 )	//最佳 1s內
// 內存大小：128MB

// 輸出格式：
// 二進位答案長度為 32bits
// 每隔 8(N-bits) 位 用 “-”間隔
// Example： 15 = 00000000-00000000-00000000-00001111

#include <stdio.h>
#include <stdlib.h>

#define SIZE 32 //總位元長度
#define Block 8 //間隔區塊大小

int main(void){

    int i = 0;              //Loop counter
    int DecNum, Ans;        //Calculus
    int counter = 0;        //Format
    int Bin[SIZE] = {0};    //Setting: Bin[SIZE] All of 0

    //scanf("%d",&DecNum);    //input data
    DecNum = 15;

    /*Calculus*/
    while (DecNum >= 1){

        /*Calculus: Dec to Bin*/
        Ans = DecNum % 2;
        DecNum /= 2;

        /*Save Bin*/
        Bin[i] = Ans;   //Save to Bin[]
        i++;    //Loop

        /*Debug*/
        if(i>SIZE){
            printf("Error! Plz check the range of Loop i\n");
            return 0;
        }
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

