//
//  Lebal #002-數學 & 計算<Math_Calculate>
//
//  PS01-骰子統計-Dice_Counter.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 22/10/2018.
//  Last modified by Waylon.Yuen on 22/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：骰子點數出現次數統計的練習
//  操作：X
//  原理：X
//  問題：太多重複的code
//  優化：利用陣列解決重複code的問題
//

#include<stdio.h>
#include<stdlib.h>  //引用 rand（）函數

int main(){

    int counter1=0, counter2=0, counter3=0;
    int counter4=0, counter5=0, counter6=0;
    int i;

    /* 6000 次的統計循環*/
    for(i=1; i<=6000; ++i){ //先++，再做內容
        int dice = rand()%6 + 1; //隨機數範圍 1～6

        /*判斷骰子號碼&統計*/
        switch(dice){
            case 1: counter1++; break;
            case 2: counter2++; break;
            case 3: counter3++; break;
            case 4: counter4++; break;
            case 5: counter5++; break;
            case 6: counter6++; break;
        }
    }

    /*Output*/
    printf("1: %d\n", counter1);
    printf("2: %d\n", counter2);
    printf("3: %d\n", counter3);
    printf("4: %d\n", counter4);
    printf("5: %d\n", counter5);
    printf("6: %d\n", counter6);

    return 0;
}