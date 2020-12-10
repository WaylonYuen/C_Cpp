//
//  Quesion_3.c
//  輸入一個值，輸出該值後10個偶數值； 奇數則下一個偶數為第一個偶數，偶數本身為j第一個偶數。
//
//  Created by Waylon.Yuen on 7/10/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
//
#include<stdio.h>

int main(){
    while(1){
        int num;
        int i = 0;
        int flag = 0;

        scanf("%d", &num);
        if(num%2 == 0){
            /*雙數*/
            printf("%d ", num);
            flag = 0;
        }
        else{
            /*單數*/
            num--;
            flag = 1;
        }

        while(i != 9 + flag){
            num = num + 2;
            printf("%d ", num);
            i++;
        }
        
        puts("\n\n");
    }
return 0;

}
