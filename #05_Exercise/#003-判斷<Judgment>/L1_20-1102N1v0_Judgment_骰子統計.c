// 編號：L1_20-1102N1v0_Judgment_骰子統計.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★☆☆☆☆ )
// 題目：骰子統計

// 運行時：
// 1、時間：NULL ( 不限 ) //最佳 3s內
// 2、內存大小：128MB

// 題目內容：
//  隨機擲骰子10000次,，分別統計各個面所被擲到的總數。
//  *隨機1~6的整數產生可使用: int dice = rand()%6+1; 取得。
//  *使用隨機數 rand() 函數必須調用: #include <stdlib.h>
//  *使用隨機數 rand() 函數必須調用: #include <time.h> 及 srand(time(NULL));

// 輸入： 
// null(無)

// 輸出：
// 請以 ("dice %d: %d\n", i, 對應統計數據) 的格式，由1～6號輸出統計的次數

// Sample input :
// null(無)

// Sample output :
// dice 1: 1545
// dice 2: 1694
// dice 3: 1670
// dice 4: 1744
// dice 5: 1690
// dice 6: 1657

// 以上僅供輸出格式參考，統計的結果非正確值。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    //創建一個大小為 6 的整數型陣列並初始化其內容為 0.
    int dice[6] = {0};

    //以系統時間來取得種子seed(種子相當於隨機碼)
    //time(NULL): 將系統時間重置到 1900年1月1日到此時此刻的秒數,
    //srand會根據時間來取得對應的種子編號以達成隨機效果.
    //(此處的隨機屬於偽隨機,若能夠百分百複製此系統以及使用相同時間會獲得一樣的種子碼,也就導致這種隨機可以人為還原,因此叫偽隨機)
    srand(time(NULL));  

    //根據題目要求, 擲骰子10000次.因此迴圈 (0 ~ 9999)
    for (int i = 0; i < 10000; i++) {
        
        //通過隨機 1~6 來模擬擲骰子的效果.
        //隨機產生 1~6 之間的整數數值(包括 1和 6本身)
        int number = rand() % 6 + 1;    //最小值及最大值範圍的控制: 6相當於是max, 而 1相當於是min.

        //根據隨機產生的數值來確定此次擲骰子所得到的結果,並將結果加到對應統計欄位中.
        //例如: 隨機數產生了一個 3號(number = 3), 那麼switch會執行 case 3, 將dict[2]的內容加一.
        switch (number) {
            case 1: dice[0]++; break;
            case 2: dice[1]++; break;
            case 3: dice[2]++; break;
            case 4: dice[3]++; break;
            case 5: dice[4]++; break;
            case 6: dice[5]++; break;
        }
    }

    //輸出統計結果
    printf("統計結果:\n");
    for (int i = 0; i < 6; i++) {
        printf("dice %d: %d\n", i+1, dice[i]);
    }

    //最終dice陣列內容統計總和應該要符合10000

    return 0;
}