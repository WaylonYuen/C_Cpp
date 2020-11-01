//
//  Lebal #007-字串<Char>
//
//  001-字元與字串-Char_And_String.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 21/10/2018.
//  Last modified by Waylon.Yuen on 21/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：練習與區分字元及字串的差別。
//  操作：X
//  原理：X
//  優化：X
//

#include<stdio.h>

/*print string array*/
void str_print(char str[]){

    int i;
    puts("String:");
    for(i=0; str[i]!='\0'; i++){//判斷是否為結尾，因為結尾為‘\0’。
        printf("%c", str[i]);// %c 定義字元輸出， %s 定義字串輸出。
    }

    puts("\n");

}

/*print char array*/
void char_print(char charA[],int number){

    int i;
    puts("char:");
    for(i=0; i<11; i++){//字串陣列長度為12
        printf("%c", charA[i]);// %c 定義字元輸出
    }

    puts("\n");

}

int main(){

    /*字串是以‘\0’結尾的字元陣列*/
    char strA[12] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
    char strB[12] = {"Hello World"};//雙引號為常用字串陣列，結尾會自動補上‘\0’
    /*strB 等同於 strA
        */

    /*字元陣列的每一個儲存格可以存放一到多個字元*/
    char charA[12] = {'H','e','l','l','o',' ','W','o','r','l','d'};//一個字元
    /*
        例如：
            charB[4] -> charB編號4所儲存的字元為3
            charB[10]-> charB編號10所儲存的字元為9
            以此類推
        */

    str_print(strA);//字串陣列，結尾‘\0’，無需知道長度
    char_print(charA, 12);//字元陣列，需要知道長度

    return 0;
}