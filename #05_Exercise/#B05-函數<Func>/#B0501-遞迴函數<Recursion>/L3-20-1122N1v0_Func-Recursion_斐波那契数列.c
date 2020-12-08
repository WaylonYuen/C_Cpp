// 編號：L3-20-1122N1v0_Func-Recursion_斐波那契数列.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★★★☆☆ )
// 題目：斐波那契数列

// 運行時：
// 1、時間：NULL ( 不限 ) //最佳 3s內
// 2、內存大小：128MB

// 題目內容:
// 利用遞迴函數輸出指定範圍的斐波那契數列.(輸入的數值範圍 0 < n <= 30)

// 額外:
// # 由於遞迴函數有嚴重的效率缺陷問題,若要印證則輸入47便可明顯看出計算效率越來越慢.
// # 輸入的數值(筆數)最大不可超過47,因為整數int的最大正數只能表達到大約21億 ->
// # 第48th的斐波那契數列會超越21億,因此會導致int溢位(可以自行嘗試)
// *注: 溢位並不會報錯,因為數值錯誤並非語法or邏輯錯誤(編譯器只會報語法錯誤, 人為導致的邏輯錯誤只有在執行時才會發生)
// (最大值+1溢位會變成最小表達數值,反之亦然)

// 輸入： 
// 輸入輸出數列筆數

// 輸出：
// 請用 ("%5d : %5d\n", index, result) 的格式, 印出迴圈編號.

// Sample input :
// 10

// Sample output： 
//  1 :     0
//  2 :     1
//  3 :     1
//  4 :     2
//  5 :     3
//  6 :     5
//  7 :     8
//  8 :    13
//  9 :    21
// 10 :    34

#include <stdio.h>
 
//副程式宣告
int Fibonaci(int i);

//主程式 
int main(void) {

   int size = 0;

   //輸入要顯示的斐波那契數列筆數
   printf("Plz input number of fibonaci seq to show. (Range: 1~45)\n");
   scanf("%d", &size);

   //安全性檢查
   if(size <= 0 || size > 45) {
      printf("Error: Out of range -> %d.\n", size);
      printf("End of run...\n");
      return 0;
   }

   //計算
   for (int i = 0; i < size; i++) {
      printf("%5d : %5d\n", i+1, Fibonaci(i));
   }

   return 0;
}

//斐波那契數副程式
int Fibonaci(int i) {
   switch (i) {
      case 0: return 0;
      case 1: return 1;
      default: return Fibonaci(i-1) + Fibonaci(i-2);  //遞迴
   }
}