// 編號 : L3_20-1106N1v0_Loop_圓形繪製_unF.c

// 程式類別 : C語言
// 基礎題 : 迴圈練習 ( 難度 ★★★☆☆ )
// 題目 : 圓形繪製

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小 : 128MB

// 題目內容 :
// 繪製一個圓形

// 輸入 : Null(無)
// 輸出 : 圓形

// Sample input : Null(無)
// Sample output : 圓形


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
            
            //判斷是否繪製圓形
            if (circle(x, y)) {
                printf("  ");

            } else {

                //圓形邊界判斷(判斷前後是否不一致,不一致表示出於圓形臨界點則繪製出來)
                if(circle(x+1, y) 
                || circle(x-1, y) 
                || circle(x, y+1)
                || circle(x, y-1)) {

                    printf(" *");
                } else {
                    printf("  ");
                }
                
            }
        }
        
        printf("\n");
    }

    return 0;
}

//座標檢查,繪製判斷
int circle(int x, int y) {
    //大於 則繪製圓形
    return (((x-R)*(x-R) + (y-R)*(y-R)) > R*R) ? 1 : 0; //三目運算法則
}