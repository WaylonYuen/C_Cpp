//
//	Lebal X
//
//  T04-售票系統.c
//	Version 2.3 
//	
//  Created by Waylon.Yuen on 27/10/2018.
//	Last modified by Waylon.Yuen on 29/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明： X
//	操作： X
//  問題： X
//	優化： X
//     
#include "Global.h"

int main(){
    int request;
    char seat[12][16];

    /*清空*/
    Empt(seat);
    menu();
    Func(seat, request);


    return 0;
}



/*選位置*/
void select_Seat(char seat[12][16], int x, int y){
    seat[x][y] = '1';
}


