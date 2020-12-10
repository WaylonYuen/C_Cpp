//
//	Lebal #002-數學 & 計算<Math_Calculate>
//
//  FM02_1-質數-Prime_Number.c
//	Version 1.3 
//	
//  Created by Waylon.Yuen on 18/10/2018.
//	Last modified by Waylon.Yuen on 26/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：輸入一整數n，判斷其是否為質數。
//          是：列印出 %d is a Prime number!
//          否：列印出 %d is not a Prime number!
//        註： 使用for迴圈

//	操作：輸入一整數，範圍是int標準。
//	優化：1、判斷n個整數是否為質數，以EOF結束程序。
//       2、限制輸入類型，int以外類型需給予警告標語。
//
#include<stdio.h>

int main(int argc, char const *argv[]){

/*變數宣告*/    
    int i,j;
    int flag = 0; //此參數 初始值會影響結果
    /*  flag = 0 ：不是prime
        flag = 1 ：是prime
        */
    int number;

/*輸入 整數*/
//    scanf("%d", &number);

/*質數判斷運算*/
    for(i=2; i<100; i++){
        for(j=2; j<100; j++){
            /*判斷能否被整除，能則不是 prime */
            if(i%j == 0){  //能被整除
                break;
            }
        }
        if(i == j){
            printf("%d\n", i);
        }
    }
    return 0;
}
