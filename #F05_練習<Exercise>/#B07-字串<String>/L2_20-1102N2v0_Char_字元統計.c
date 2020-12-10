// 編號：L2_20-1102N2v0_Char_字元統計.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★★☆☆☆ )
// 題目：字元統計

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小：128MB

// 題目內容：
// 手動輸入一筆字串內容，該字串長度不超過100。根據輸入的字串統計字串中所包含的字母總數。(不包括空白及特殊符號)
// 統計內容包含：a~z，A～Z，0～9 及 逗號 和 句號。

// 輸入： 
// 手動輸入字串

// 輸出：
// 請以 “Counter: %d\n” 的格式，輸出統計結果

// Sample input :
// Today is sunny day.

// Sample output： 
// Counter: 16

#include <stdio.h>

int main(void) {

    int i = 0;              //字串索引
    int counter = 0;        //統計結果
    char str[100] = {" "};  //輸入的字串內容

    //會被納入統計的字元內容
    char dict[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,."};
    
    printf("請輸入字串內容.\n");
    scanf("%[^\n]", str);   // %[^\n] 表示在沒有遇到換行前,將輸入的內容保存到str裡面去

    //如果字串不是最後一個,則持續計算
    while(str[i] != '\0') {
        
        int j = 0;

        //如果被納入統計的字串不是最後一個,這繼續查找比對
        while (dict[j] != '\0') {
            
            //如果在被納入統計的dict中找到了對應字元, 則統計結果加 1. 並且跳出dict的while迴圈.
            if(str[i] == dict[j]) {
                counter++;
                break;//這個break會跳出dict的while迴圈
            }

            j++; //比對下一個dict內容
        }
        
        i++; //查看下一個字元內容.
    }

    //輸出結果
    printf("Counter: %d\n", counter);

    return 0;
}