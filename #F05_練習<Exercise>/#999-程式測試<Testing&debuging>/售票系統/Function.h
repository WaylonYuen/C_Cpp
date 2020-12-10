#include "Global.h"

/* Global.h 只能被主程式給加載，否者會產生衝突 */
#include<stdio.h>
#include<stdlib.h>

#ifndef FUNCTION_H
#define FUNCTION_H

#define seatNumber char seat[12][16]

/*菜單 Menu*/
void menu(){
    printf( "菜單\n"
            "---------------------------------\n"
            "press 1 顯示選項\n"
            "press 2 選擇您需要的座位號碼\n"
            "press 3 修改位置\n"
            "press 4 退出\n"
            "---------------------------------\n");
}

/*攻能區 functions Switch*/
void Func(seatNumber, int request){

/* Variable */
    int x,y;
    /* Function Key */
    switch(request){

        case 1:
            system("clear");
            menu();
            Output(seat);
            break;

        case 2:
            printf("Plz enter the coor\n");
            scanf("%d%d", &x, &y);
            select_Seat(seat, x, y);
            break;

        case 3:
            break;

        case 4:
            exit(1);
            break;

        default:
            printf("Miss Error\n");
            break;
    }
}

/*輸出 Output*/
void Output(seatNumber){
    int i,j;
    puts("----------------------------------");
    for(i=0; i<12; i++){
        for(j=0; j<16; j++){
            printf("%c  ", seat[i][j]);
        }
        puts("\n");
    }
    puts("----------------------------------");
}

/*清空 empty*/
void Empt(seatNumber){
    int i,j;

    /*清空*/
    for(i=0; i<12; i++){
        for(j=0; j<16; j++){
            seat[i][j] = '0';
        }
    }

}


#endif