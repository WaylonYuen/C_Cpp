// 編號 : L2_20-1026N2v1_Loop_右下角三角形加邊框.c

// 程式類別 : C語言
// 基礎題 : 陣列練習 ( 難度 ★★☆☆☆ )
// 題目 : 右下角三角形加邊框

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小 : 128MB

// 題目內容 :
// 利用迴圈輸出一個右下角三角形加邊框 每單位以符號*表示, 並且邊框以符號@表示.

// 輸入 : 
// 輸入三角形大小

// 輸出 :
// 輸出帶邊框的右下角三角形

// Sample input :
// 5

// Sample output :
// @
// @@
// @*@
// @**@
// @@@@@ 

#include <stdio.h>

int main(void) {

    int size = 0;

    printf("plz input triangle size.\n");
    scanf("%d", &size);

    //安全性檢查
    if(size <= 0) {
        printf("Size should be larger than 0.\n");
        printf("End of run...\n");
        return 0;
    }

    //繪製帶邊框的右下角三角形
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {

            if(
               i == size - 1    //下邊框
            || j == i           //右邊框
            || j == 0)          //左邊框
            {
                printf("@");
            } else {
                printf("*");
            }     
        }

        //換行到下一層
        printf("\n");
    }

    return 0;
}