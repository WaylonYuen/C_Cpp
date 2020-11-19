// 編號 : L2_20-1026N7v1_Loop_上等腰三角形加邊框.c

// 程式類別 : C語言
// 基礎題 : 陣列練習 ( 難度 ★★☆☆☆ )
// 題目 : 上等腰三角形加邊框

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小 : 128MB

// 題目內容 :
// 利用迴圈輸出一個上等腰三角形加邊框, 每單位以符號*表示

// 輸入 : 
// 輸入三角形大小

// 輸出 :
// 上等腰三角形加邊框

// Sample input :
// 5

// Sample output : 
//       @
//      @*@
//     @***@
//    @*****@
//   @@@@@@@@@

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

    size *= 2;

    //繪製上等腰三角形加邊框
    for (int i = 0; i < size; i+=2) {
        
        for (int j = i; j <= size; j+=2) {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++) {

            if (
                   j == 0
                || i == size - 2
                || j == i
            ) {
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