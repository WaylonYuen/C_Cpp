//
//	Lebal #001-入門程式<Fundamental>
//
//  CF-01F03_2-常量Const-constant_const.c
//	Version 1.0 
//	
//  Created by Waylon.Yuen on 27/10/2018.
//	Last modified by Waylon.Yuen on 27/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明： 預處理器定義常量的形式
//	操作： X
//  問題： X
//	優化： X
// 
#include <stdio.h>

/* #define 預處理器定義常量的形式 */ 
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
 
int main(){
 
    int area;  
    
    area = LENGTH * WIDTH;
    printf("value of area : %d", area);
    printf("%c", NEWLINE);
    
    return 0;
}