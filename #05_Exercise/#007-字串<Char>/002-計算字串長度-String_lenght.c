//
//  Lebal #007-字串<Char>
//
//  002-計算字串長度-String_lenght.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 21/10/2018.
//  Last modified by Waylon.Yuen on 21/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：計算字串陣列 大小&長度
//  操作：X
//  原理：X
//  優化：X
//

#include<stdio.h>
#define size 12 //自定義大小

int str_len(char str[]){

    //回傳第一個‘\0’的位址
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main(){

    char str[size] = "Hello World";//字串陣列 -> 雙引號，結尾會自動補上‘\0’
    /* 1、陣列str[]實際大小為 11 + 1 = 12，因為包含了‘\0’
        2、實際表達：
            char str[12] = { 'H', 'e', 'l', 'l', 'o', ' ',
                             'W', 'o', 'r', 'l', 'd', '\0'};
        3、大小：
            #如果字元/字串內容大小 小於 定義大小則：
            char str[15] = { 'H', 'e', 'l', 'l', 'o', ' ',
                             'W', 'o', 'r', 'l', 'd', '\0', '\0', '\0', '\0'};
            '\0'打後的3個‘\0’ 為 未使用/浪費的空間

            #如果字元/字串內容大小剛剛好則：
            char str[11] = { 'H', 'e', 'l', 'l', 'o', ' ',
                             'W', 'o', 'r', 'l', 'd'};
            ‘\0’沒有空間定義，結尾為‘d’。
            用途：可以自定義結尾符號，不一定是‘\0’。
            注意：但該陣列不可被用於一般字元/字串陣列用途。例如：printf（）等

            #如果字元/字串內容大小 大於 定義大小則：不合法，錯誤。

            *重點：字串長度 不一定等於 所儲存的字元整列的 大小。
                字元大小 有可能比字串長度 多1 或者 是多很多。 ——> 如同 3、大小
                */

    
    printf("Length: %zu\n", sizeof(str));// sizeof(): 計算大小、所佔據的空間（包括‘\0’）——>實際大小
    printf("Length: %d\n", str_len(str));//str_len(): 計算字串長度，不包括‘\0’
    /* 可改變 size 來自定義大小看結果*/
    /* %zu 為 C99 標準，
        如果編譯器不支援則需改為 %u 或者 %lu。
        */


    return 0;
}