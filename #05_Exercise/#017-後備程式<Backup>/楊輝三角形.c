//
//	Lebal X
//
//  T04-售票系統.c
//	Version 2.3 
//	
//  Created by Waylon.Yuen on 27/10/2018.
//	Last modified by Waylon.Yuen on 29/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明： X
//	操作： X
//  問題： X
//	優化： X
//     
#include<stdio.h>

#define SIZE 11

int main(){

    int i,j;
    int A[SIZE][SIZE] = {};

    /* 處理最外圍的1 */
    for(i=0; i<SIZE; i++){
        A[i][0] = 1;
        A[i][i] = 1;
    }

    /* 處理內部的運算 */
    for(i=2; i<SIZE; i++){
        for(j=1; j<i; j++){
            /* 座標運算 */
            A[i][j] = A[i-1][j-1]+A[i-1][j];
        }
    }

    /* 輸出結果 */
    for(i=0; i<SIZE; i++){
        for(j=0; j<=i; j++){
            printf("%d ", A[i][j]);
        }
        puts("\n");
    }



    return 0;
}