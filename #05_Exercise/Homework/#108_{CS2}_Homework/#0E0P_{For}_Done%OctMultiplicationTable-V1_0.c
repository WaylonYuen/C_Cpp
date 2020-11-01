//
//	8進位乘法表
//
//  Created by Waylon.Y on 21/05/2020.
//	Last modified by Waylon.Y on 22/05/2020
//  Copyright © 2020年 Oracragron. All rights reserved.
//
//  說明： 按照指定格式輸出8進位乘法表
//	操作： Show
//  問題： Null
//	優化： Null
//
#include <stdio.h>

#define RowStyle 61 //橫線長度

void ShowRowBorther(void) {
    printf("\n");
    for (size_t i = 0; i < RowStyle; i++) {
        printf("-");
    }  
    printf("\n");
}

int main(void) {

    int counter = 0;

    ShowRowBorther();

    //show first row number
    printf("|  X  |");
    for (counter = 9; counter > 0; counter--) {
        printf("%3d  |", counter);
    }
    ShowRowBorther();

    //Column number
    for (int i = 1; i < 10; i++) {
        //Row number
        for (int j = 9; j > 0; j--) {

            //show first Column number
            if(j == 9) {
                printf("|%3d  |", ++counter);
            }

            //show Oct Product 乘積
            printf(" %3.3o |", i * j);
        }
        ShowRowBorther();
    }

    return 0;
}