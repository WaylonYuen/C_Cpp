//
//	For迴圈練習
//
//  Created by Waylon.Y on 21/05/2020.
//	Last modified by Waylon.Y on 22/05/2020
//  Copyright © 2020年 Oracragron. All rights reserved.
//
//  說明： 輸入整數1～9,再根據輸入的數字輸出各種圖案
//	操作： Show
//  問題： Null
//	優化： Null
// 
#include <stdio.h>

void Show(int start, int end, char str) {
    if(str == '\0') {
        for (int i = start; i < end; i++) {
            printf("%d", i);
        }
    } else {
        for (int i = start; i < end; i++) {
            printf("%c", str);
        }
    }
}

void Show_1(int index) {

    for (int i = index; i >= 1; i--) {
        Show(1, i + 1, '\0');       //Show number
        Show(0, index - i, ' ');    //ToBig: Blank
        Show(0, index, '^');        //Blank
        Show(0, i, ' ');            //Blank
        Show(0, index - i + 1, '*');//ToBig: Show Star
        puts("");
    }

    for (int i = 2; i <= index; i++) {
        Show(1, i + 1, '\0');       //Show number
        Show(0, index - i, ' ');    //ToBig: Blank
        Show(0, index, '^');        //Blank
        Show(0, i, ' ');            //Blank
        Show(0, index - i + 1, '*');//ToBig: Show Star
        puts("");
    }

}

void Show_2(int index) {

    for (int i = 0; i < index; i++) {

        //Star
        for (size_t j = 0; j < i; j++) {
            printf(" ");
        }

        //number
        for (size_t k = index - i; k > 0; k--) {
            printf("%d", index - i);
        }

        for (size_t k = index - i; k > 0; k--) {
            printf("%d", index - i);
        }

        puts("");
    }

    for (int i = index-2; i >= 0; i--) {

        //Star
        for (size_t j = 0; j < i; j++) {
            printf(" ");
        }

        //number
        for (size_t k = index - i; k > 0; k--) {
            printf("%d", index - i);
        }

        for (size_t k = index - i; k > 0; k--) {
            printf("%d", index - i);
        }

        puts("");
    }

}

void Show_3(int index) {

    int counter = 0;
    
    for (int i = index - 1; i >= 0; i--) {

        for (int j = index; j > i; j--) {
            
            //Style
            if(j == index) {
                for (size_t j = 0; j < i; j++) {
                    printf(" ");
                }
            }

            //Number
            printf("%d", index - i);

            //Style
            if(j == (index - counter)) {
                counter++;
                continue;
            }

            //Blank
            printf("^");
        }

       puts(""); 
    }
    
    counter = 2;
    for (int i = 1; i <= index; i++) {

        for (int j = index; j > i; j--) {
            
            //Style
            if(j == index) {
                for (size_t j = 0; j < i; j++) {
                    printf(" ");
                }
            }

            //Number
            printf("%d", index - i);

            //Style
            if(j == (counter)) {
                counter++;
                continue;
            }

            //Blank
            printf("^");
        }

       puts(""); 
    }

}

int main(void) {

    int number = 0;

    while(1) {
        scanf("%d", &number);
        if(number <= 0 || number > 9) {
            printf("Plz enter 1~9.\n");
        } else {
            printf("Show:\n\n");
            break;
        }
    }

    Show_1(number);
    printf("\n");

    Show_2(number);
    printf("\n");

    Show_3(number);

    return 0;
}