// 編號：L1_20-1130N2v0_Fundamental_第一個程式.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ☆☆☆☆☆ ) -> (tmp: ★ ☆)

// 題目：第一個C語言程式

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小：128MB
// 題目內容：
// 輸出 Hello world!\n this is my first C program.\n

// 輸入：
// null(無)

// 輸出：
// Hello world!\nthis is my first C program.\n

// Sample input :
// null(無)

// Sample output： 
// Hello world!
// this is my first C program.

//頭文件庫
#include <stdio.h> //引用標準輸入輸出流庫,
//定義了常用的 -> 
//輸入: scanf()函數
//輸出: printf()函數
//若調用以上兩個函數時, 沒有引用stdio.h文件則會報錯(錯誤為: 找不到清晰的定義or宣告)

//主程式 -> 程式入口
int main(void) {

    //輸出內容
    printf("Hello world!\nthis is my first C program.\n");   // ('/n'表示換行)

    //結束運行
    return 0;   //返回整數 0,以表示程式無異常&停止運行
}