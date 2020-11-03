// 編號：L1_20-1026N1v0_Loop.c

// 程式類別：C語言
// 基礎題：For迴圈練習 ( 難度 ★☆☆☆☆ )
// 題目：長方形

// 時間：NULL ( 不限 ) //最佳 1s內
// 內存大小：128MB

// 題目內容：
// 利用for迴圈畫出 5*5大小的正方形星星

// Sample input :
// null(無)

// Sample output：
// *****
// *****
// *****
// *****
// *****

// *注意：
// 1、必須逐個星星輸出, 不可直接使用printf來直接繪製.

// *提示：
// 1、利用雙重for迴圈來實現

#include <stdio.h>

int main(void) {

    int x_size = 5; // x軸長度
    int y_size = 5; // y軸長度

    //進階：通過輸入 x軸和 y軸的長度來繪製指定大小的長方形
    printf("Plz input x and y coordinate size.\n");
    scanf("%d%d", &x_size, &y_size);

    //控制 y軸的for迴圈
    for (int y = 0; y < y_size; y++) {

        //控制 x軸的for迴圈
        for (int x = 0; x < x_size; x++) {
            printf("*");
        }

        //同一行輸出完指定星星數量後換行
        printf("\n");
    }

    return 0;
}