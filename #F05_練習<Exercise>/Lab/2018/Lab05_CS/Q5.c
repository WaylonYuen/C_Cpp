//
//  Quesion_1.c
//  輸入一個值，計算該值第201個偶數值，奇數則下一個偶數為第一個偶數，偶數本身為第一個偶數。
//
//  Created by Waylon.Yuen on 7/10/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
//
#include<stdio.h>

int main(){
        int num;
        int i = 1;

        scanf("%d", &num);
        if(num%2 != 0){
            /*單數*/
            num++;
            //printf("id:%d\n", num);
        }

        while(i != 201){
            num = num + 2;
            //printf("id:%d   ans:%d \n", i, num);
            i++;
        }

        printf("%d ", num);
        puts("\n\n");
return 0;

}
