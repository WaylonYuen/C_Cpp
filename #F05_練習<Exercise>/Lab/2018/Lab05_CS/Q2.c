//
//  Quesion_2.c
//  n階乘
//
//  Created by Waylon.Yuen on 7/10/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
//
#include<stdio.h>

int main(){

    int i;
    int num;
    int sum=1;

    scanf("%d", &num);
    for(i=1; i<=num; i++){
        sum = sum * i;  //階乘運算
    } 
    printf("ans: %d\n", sum);

return 0;
}
