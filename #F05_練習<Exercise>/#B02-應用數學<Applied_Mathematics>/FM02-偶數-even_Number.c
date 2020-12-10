//
//	Lebal #002-FM02
//
//  FM02-偶數-even_Number.c
//	Version 1.2 
//	
//  Created by Waylon.Yuen on 18/10/2018.
//	Last modified by Waylon.Yuen on 19/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：輸入整數，判斷其是否為偶數。
//	操作：輸入一整數，範圍是int標準。
//	優化：1、判斷n個整數是否為偶數，以EOF結束程序。
//       2、限制輸入類型，int以外類型需給予警告標語。
//
#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int get;

    scanf("%d", &get);

    if(get%2 == 0){
        printf("%d is a even number. \n", get);
    }
    else{
        printf("%d is not a even number. \n", get);
    }

    puts("end of run\n\n");

    return 0;
}
