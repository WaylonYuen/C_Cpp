// 編號：L3-20-1123N1v0_Func-Recursion_階乘.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★★★☆☆ )
// 題目：階乘

// 運行時：
// 1、時間：NULL ( 不限 ) //最佳 3s內
// 2、內存大小：128MB

// 題目內容:
// 利用遞迴函數輸出指定範圍的階乘.

// 輸入： 
// 輸入輸出數列筆數(*注: 階乘答案不能超過int最大表達值,否則會溢位)

// 輸出：
// 請用 ("%4d 的階乘為: %d\n", index, result) 的格式, 印出迴圈編號.

// Sample input :
// 10

// Sample output： 
//    1 的階乘為: 1
//    2 的階乘為: 1
//    3 的階乘為: 2
//    4 的階乘為: 6
//    5 的階乘為: 24
//    6 的階乘為: 120
//    7 的階乘為: 720
//    8 的階乘為: 5040
//    9 的階乘為: 40320
//   10 的階乘為: 362880


#include <stdio.h>
 
//副程式宣告
int Factorial(unsigned int i);

//主程式
int main(void) {

    int size = 0;

    //輸入要顯示的階乘筆數
    printf("Plz input number to show factorial seq.\n");
    scanf("%d", &size);

    //安全性檢查
    if(size <= 0) {
        printf("Error: Out of range -> %d.\n", size);
        printf("End of run...\n");
        return 0;
    }

    //計算
    for (int i = 0; i < size; i++) {
        printf("%4d 的階乘為: %d\n", i+1, Factorial(i));
    }

    return 0;
}

//副程式定義
int Factorial(unsigned int i) {

    //三元運算符
    return (i <= 1) ? 1 : i * Factorial(i - 1);
}