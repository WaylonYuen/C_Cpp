//
//	Lebal #001-入門程式<Fundamental>
//
//  CF-01F02-變量-variate.c
//	Version 1.0 
//	
//  Created by Waylon.Yuen on 27/10/2018.
//	Last modified by Waylon.Yuen on 27/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明： X
//	操作： X
//  問題： X
//	優化： X
// 
#include <stdio.h>
 
/* 變量聲明 */
extern int a, b;
extern int c;
extern float f;
 
int main ()
{
    /* 變量定義 */
    int a, b;
    int c;
    float f;
    
    /* 初始化 */
    a = 10;
    b = 20;
    
    /* 整數加法運算 */
    c = a + b;
    printf("value of c : %d \n", c);

    /* 浮點運算 */
    f = 70.0/3.0;
    printf("value of f : %f \n", f);
    
    return 0;
}