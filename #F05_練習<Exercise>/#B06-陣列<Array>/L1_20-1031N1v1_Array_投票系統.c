// 編號：L1_20-1031N1v0_Loop_投票系統.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★☆☆☆☆ )
// 題目：投票系統

// 運行時：
// 1、時間：NULL ( 不限 ) //最佳 3s內
// 2、內存大小：128MB

// 題目內容：
// 逢甲大學資電系正好要選班代，大家決定用投票表決的方式，每人一票，由得票數最多的人擔任。
// 如果不巧最高票有兩人或以上，那由編號比較前面的人擔任班代。
// 請同學寫個程式，幫忙統計出班代人選。

// 輸入： 
// 首先會有一個數字 n (1≦n≦100) 代表班上的人數。
// 接下來會有 n 個整數，每個數字都會是在 1 ~ n 之間，代表每個同學的選擇。

// 輸出：
// 請用 "%d (%d votes)\n" 的格式，印出得票數最高的同學的號碼以及票數。

// Sample input :
// 10
// 4
// 4
// 2
// 3
// 4
// 6
// 6
// 6
// 9
// 2

// Sample output： 
// 4 (3 votes)

#include <stdio.h>
#define SIZE 100    //預先定義(全域宣告): int SIZE = 100;

int main(void) {

    //創建一個空間為SIZE大小的陣列並且初始化其內容為0,用以保存每位學生所獲得的票數.
    int student[SIZE] = {0};

    int votes = 0;  //獲得的票數
    int number = 0; //資料筆數
    int max = -1;   //獲得最多票數的學生索引值(初始化為-1,因為陣列範圍 0～ SIZE, 以-1表示默認)

    //輸入資料筆數
    scanf("%d", &number);

    //Add: 安全性檢查
    if(number <= 0) {
        printf("Error: No student => {%d}", number);
        return 0;
    }

    //輸入每位同學所投票的編號
    for (int i = 0; i < number; i++) {
        scanf("%d", &votes);

        //Bug1的修復: 安全性檢查
        //若輸入超出範圍, 則要求用戶重新輸入.
        if(votes < 0 || SIZE <= votes) { 
            printf("Error: Out of range(0 ~ %d) => {%d}\n", SIZE, votes);
            i--;    //還原索引,讓用戶重新輸入
            continue;   //忽略此回合,直接跳到for終點判斷
        }

        student[votes]++;//根據投票編號作為被投票同學的索引值,將內容++(即: 加1的意思)
    }

    //逐個找出票數最多的同學
    for (int i = 0; i < SIZE; i++) {

        //如果該名同學的票數比目前最高票數的同學還要多,則替換最高票數同學的索引值(索引值相當於同學的id)
        if(student[i] >= max) {
            max = i;
        }
    }
    
    //輸出結果
    printf("%d(%d votes)", max, student[max]);

    return 0;
}