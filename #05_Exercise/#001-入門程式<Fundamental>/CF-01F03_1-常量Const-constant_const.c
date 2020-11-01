//
//	Lebal #001-入門程式<Fundamental>
//
//  CF-01F03_1-常量Define-constant_define.c
//	Version 1.0 
//	
//  Created by Waylon.Yuen on 27/10/2018.
//	Last modified by Waylon.Yuen on 27/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明： const 前缀聲明指定类型的常量
//	操作： X
//  問題： X
//	優化： X
// 
#include <stdio.h>
 
int main(){

    /* const 常量定義 */
    const int  LENGTH = 10;
    const int  WIDTH  = 5;
    const char NEWLINE = '\n';

    int area;  
    
    area = LENGTH * WIDTH;
    printf("value of area : %d", area);
    printf("%c", NEWLINE);
 
   return 0;
}