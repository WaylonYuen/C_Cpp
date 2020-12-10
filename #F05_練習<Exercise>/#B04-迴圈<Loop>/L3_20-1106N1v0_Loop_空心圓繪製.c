// 編號 : L3_20-1106N1v0_Loop_空心圓繪製_unF.c

// 程式類別 : C語言
// 基礎題 : 迴圈練習 ( 難度 ★★★☆☆ )
// 題目 : 空心圓繪製

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小 : 128MB

// 題目內容 :
// 繪製一個空心圓

// 輸入 : Null(無)
// 輸出 : 空心圓

// Sample input : Null(無)
// Sample output : 空心圓


#include <stdio.h>
#include <stdlib.h>

//圓形半徑
const int R = 20;

//副程式宣告
int circle(int x, int y);

//主程式
int main(void) {

    for(int y = 0; y <= 2*R; ++y) {
        for(int x = 0; x <= 2*R; ++x) {
            
            //判斷是否繪製空心圓
            if (circle(x, y)) {
                printf(" *");
            } else {
                printf("  ");
            }
        }
        
        printf("\n");
    }

    return 0;
}

//座標檢查,繪製判斷
int circle(int x, int y) {
    //大於 則繪製空心圓
    return (((x-R)*(x-R) + (y-R)*(y-R)) > R*R) ? 1 : 0; //三目運算法則
}