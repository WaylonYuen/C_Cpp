// 編號：L2-20-1118N1v0_Func-Recursion_迴圈模擬.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★★☆☆☆ )
// 題目：遞迴迴圈模擬

// 運行時：
// 1、時間：NULL ( 不限 ) //最佳 3s內
// 2、內存大小：128MB

// 題目內容：
// 利用遞迴方法模擬迴圈效果
// 1、宣告一個副程式 void Loop(int number); //number為迴圈編號
// 2、迴圈10次,分別由大到小輸出

// 輸入： 
// null(無)

// 輸出：
// 請用 "%d\n" 的格式，印出迴圈編號。

// Sample input :
// null(無)

// Sample output： 
// 10
// 9
// 8
// 7
// 6
// 5
// 4
// 3
// 2
// 1

#include <stdio.h>

//副程式宣告
void Loop(int number);

//主程式
int main(void) { 

    //呼叫副程式
    Loop(10);   //10 為迴圈次數

    return 0;
}

//副程式定義
//等同於 -> for(int number = 10; number >= 0; number--){ do something }
void Loop(int number) {

    //副程式結束判斷 (*注: 只要通過了if判斷, 則Loop副程式會繼續自己呼叫自己來實現下一輪迴圈)
    if(0 < number){

        //顯示當前結果
        printf("%d\n", number);

        //遞迴呼叫(*注: 當前為Loop副程式中, 卻又呼叫自己Loop副程式 則稱之為遞迴呼叫)
        Loop(--number); //number參數必須先做減 1,再作為參數傳入Loop副程式中(否則number變數永遠不會改變,則if判斷永遠成立而導致死循環)
    }

    return; //無視後續內容,直接返回呼叫該程式的對象(只有當副程式回傳值型態宣告為void時才能使用次方法, 否則必須回傳該型態變數)
}