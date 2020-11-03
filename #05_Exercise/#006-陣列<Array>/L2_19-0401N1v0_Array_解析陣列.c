// 編號：L2_19-0401N1v0_Array.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★★☆☆☆ )
// 題目：解析陣列

// 時間：NULL ( 不限 ) //最佳 1s內
// 內存大小：128MB

// 題目內容：
// 創建一個SIZE為10的Arr字元陣列, 並初始化Arr陣列內容：A～J (編號：0~9):
// 例如 -> Arr[10] = { A,B,C,D,E,F,G,H,I,J };
// 隨機輸入10筆0～9範圍內10個索引值, 輸出根據編號所輸入的英文順序。

// 輸入：
// 隨機輸入一個整數 n (0 ≦ n ≦ 9), 代表Arr陣列的索引值.
// 接下來根據輸入的整數(索引值), 從 Arr陣列中取得對應的英文字母.

// 輸出：
// 請以 printf(“Ans[%d] = %d\n”, ??); 的格式輸出指定索引值的英文字母.

// Sample input :
// 5
// 4
// 3
// 8
// 7
// 9
// 1
// 2
// 0
// 6

// Sample output：
// Ans[0] = F
// Ans[1] = E
// Ans[2] = D
// Ans[3] = I
// Ans[4] = H
// Ans[5] = J
// Ans[6] = B
// Ans[7] = C
// Ans[8] = A
// Ans[9] = G

#include<stdio.h>
#define SIZE 10    //預先定義(全域宣告): int SIZE = 10;

int main(void){

    int index = -1; //索引值初始化為 -1
    char Ans[SIZE] = {' '}; //保存答案: 內容初始化為空白
    char Arr[SIZE] = {'A','B','C','D','E','F','G','H','I','J'}; //初始化內容

    //輸入整數(索引值)
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &index);
        Ans[i] = Arr[index];    //從Arr中找到對應的英文保存到Ans中
    }

    //輸出結果
    for (int i = 0; i < SIZE; i++) {
        printf("Ans[%d] = %c\n", i, Ans[i]);
    }

    return 0;
}