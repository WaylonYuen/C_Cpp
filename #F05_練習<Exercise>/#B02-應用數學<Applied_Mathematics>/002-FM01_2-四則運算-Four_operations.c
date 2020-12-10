//
//	Lebal #002-數學 & 計算<Math_Calculate>
//
//  002-FM01_2-四則運算-Four_operations
//	Version 1.0 
//	
//  Created by Waylon.Yuen on 27/10/2018.
//	Last modified by Waylon.Yuen on 27/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明： 輸入兩整數及運算符號並輸出計算結果。
//          
//
//	操作： 
//          
//  問題： X
//	優化： 
//      

#include<stdio.h>

int main(){

/*變數宣告*/
    int NumA, NumB;
    float ans;
    char op;

/*無限循環*/
    while(1){

        puts("----------------\n");
    /*輸入 整數*/
        scanf("%d %c %d", &NumA, &op, &NumB);

    /*輸入內容判斷*/
        if(NumA == 0 && NumB == 0){
            break;
        }

    /*功能選項*/
        switch(op){
            
            /*加法*/
            case '+':
                ans = NumA+NumB;
                printf("\tAns: %.0f\n", ans);
                break;

            /*減法*/
            case '-':
                ans = NumA-NumB;
                printf("\tAns: %.0f\n", ans);
                break;

            /*乘法*/
            case '*':
                ans = NumA*NumB;
                printf("\tAns: %.0f\n", ans);
                break;

            /*除法*/
            case '/':
                ans = NumA/NumB;
                printf("\tAns: %.1f\n", ans);//輸出一位小數
                break;

            /*輸入內容有誤*/
            default:
                printf("Error\n");
                break;
        }
    }
    return 0;
}