//
//  Quesion_3.c
//  輸入一個值，輸出該值後10個偶數值； 奇數則下一個偶數為第一個偶數，偶數本身為j第一個偶數。
//
//  Created by Waylon.Yuen on 7/10/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
//
#include<stdio.h>

int main(){

    int i;
    int num;

    scanf("%d", &num);

    if(num%2 == 0){
        /*偶數*/
        for(i=0; i<=9; i++){     //循環11次
            printf("%d ", num);
            num+=2; 
        }
    }
    else{
        /*奇數*/
        num++;
        for(i=0; i<=9; i++){     //循環11次
            printf("%d ", num);
            num+=2; 
        }
    }


return 0;

}
