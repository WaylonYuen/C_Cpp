//
//  Quesion_1.c
//  X 累加至 Y, Assume:X<Y
//
//  Created by Waylon.Yuen on 7/10/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
//
#include<stdio.h>

int main(){
    while(1){
        int min, max;
        int sum;
        int i;

        scanf("%d%d", &min, &max);
        if(min < max){    
            for(i=min; i<=max; i++){
                sum+=i;
            }
        printf("%d", sum);
        }
        else{
            puts("error\n");
        }
    }
    return 0;

}
