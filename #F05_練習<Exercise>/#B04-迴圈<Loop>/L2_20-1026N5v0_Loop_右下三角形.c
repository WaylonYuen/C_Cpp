// 編號 : L2_20-1026N2v0_Loop_右下角三角形.c

// 程式類別 : C語言
// 基礎題 : 陣列練習 ( 難度 ★★☆☆☆ )
// 題目 : 右下角三角形

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小 : 128MB

// 題目內容 :
// 利用迴圈輸出一個右下角三角形, 每單位以符號*表示

// 輸入 : 
// 輸入三角形大小

// 輸出 :
// 右下角三角形

// Sample input :
// 5

// Sample output : 
//       *
//      **
//     ***
//    ****
//   *****
//  ******

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

    //繪製右下角三角形
    for (int i = 0; i <= size; i++) {
        
        for (int j = i; j <= size; j++) {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++) {
            printf("*");
        }

        //換行到下一層
        printf("\n");
    }

    return 0;
}