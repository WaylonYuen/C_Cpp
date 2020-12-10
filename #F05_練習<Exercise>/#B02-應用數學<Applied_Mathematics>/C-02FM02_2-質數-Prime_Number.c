//
//	Lebal 數學 & 計算<Math_Calculate>
//
//  質數-Prime_n.c
//	Version 1.0 
//	
//  Created by Waylon.Yuen on 26/10/2018.
//	Last modified by Waylon.Yuen on 26/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明： 輸入一整數n，判斷其是否為質數。
//          是：列印出 Prime
//          否：列印出 大於一且能整除n最小的數
//        註： 使用for迴圈
//
//	操作： 
//          輸入：一整數n
//          輸出：說明欄是&否的結果
//  問題： X
//	優化： 1、判斷n個整數是否為質數，以EOF結束程序。
//        2、限制輸入類型，int以外類型需給予警告標語。
//       

#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[]){

/*變數宣告*/    
    int i;
    int flag = 0; //此參數 初始值會影響結果
    /*  flag = 0 ：不是prime
        flag = 1 ：是prime
        */
    int n; //number
    int sqrtN; //開根 number

/*輸入 整數*/
    scanf("%d", &n);

/*加速判斷速度*/
    sqrtN = sqrt(n); //減少質數循環次數

/*質數判斷運算*/
    for(i=2; i<sqrtN; i++){

        /*判斷能否被整除，能則不是 prime */
        if(n%i == 0){ //此時的 ‘i’ 為能夠整除n的最小數
            /*不是 prime*/ 
            flag = 1;
            break;
        }
    }

/*判斷flag決定是否為prime*/
    if(flag != 1){
        /*是：列印出 Prime*/
        printf("Prime");
    }
    else{
        /*否：列印出 大於一且能整除n最小的數*/
        printf("%d", i);
    }

    return 0;
}
