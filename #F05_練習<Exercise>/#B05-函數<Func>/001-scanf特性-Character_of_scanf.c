//
//  Lebal #009-函數<Func>
//
//  001-scanf特性-Character_of_scanf.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 21/10/2018.
//  Last modified by Waylon.Yuen on 21/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：使用 scanf() 讀入資料的特性 
//  操作：輸入 整數
//  原理：X
//  問題：只能輸入一次內容，即便內容讀取失敗也會停止立刻停止程式，可利用while判斷輸入直到輸入內容成功為止。
//  優化：X
//

#include<stdio.h>

int main(){

    int number;

    if(scanf("%d", &number) == 1){// '1'為讀取成功，‘0’為讀取失敗
    /* 1、scanf()會忽略空格內容
       2、輸入abc字元而非整數，
            輸入會失敗，number的內容也不會被改變，
            由於沒有初始化number的值，因此此時的number為未定義行為，
            print出的number內容為未定義行為。
            *為此添加 if 判斷輸入是否成功
        */

        printf("%d\n", number);
    }
    else{
        printf("Error: Invalid input\n");
    }

    /*優化*/
    /*
        讀取內容直到輸入內容被讀取成功為止。防止輸入錯誤內容而導致未定義行為
        int number;
        while(scanf("%d", &number) != 1){
            printf("Error: Invalid input\n");
        }
        printf("%d\n", number);
    */

    return 0;
}