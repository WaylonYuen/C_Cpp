//
//  Quesion_1.c
//  由3累加3至300，Example：3+6+9+12+⋯⋯+300
//
//  Created by Waylon.Yuen on 7/10/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
//
#include<stdio.h>

int main(){

    int i;
    int sum=0;
    
    for(i=3; i<=300; i+=3){
        sum+=i;
        //printf("%d   %d\n",i,sum);
    }
    printf("%d",sum);


    return 0;
}
