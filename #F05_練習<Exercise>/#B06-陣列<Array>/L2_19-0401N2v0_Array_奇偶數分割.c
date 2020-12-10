// 編號：L2_19-0401N2v0_Array_奇偶數分割.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★★☆☆☆ )
// 題目：奇偶數分割

// 運行時：
// 1、時間：NULL ( 不限 ) //最佳 3s內
// 2、內存大小：128MB

// 題目內容：
// 創建一個 SIZE為100的 Arr陣列, 並給初始化內容(由大到小 100 ~ 1)
// 其次將所有奇數順序(由小到大)存放到Arr陣列中, 而偶數則尾隨其後, 
// 依序存放(由小到大)到Arr陣列中。

// 輸入：
// null(無)

// 輸出：
// 請以 printf(“Arr[%d] = %d\n”, ??); 的格式輸出內容.

// *注意：
// 不能使用外部覆蓋法(例如直接使用for(i=0; i<=50; i++)來儲存奇數覆蓋到Arr陣列中),必須通過 Arr陣列初始化內容進行交換.
// 

// *提示：
// 使用Arr2 來轉儲 Arr 中所有的奇數，
// 再使用Arr3 來轉儲 Arr 中所有的偶數，
// 再依次 回存到 Arr中。
// 缺點：需要額外更多的空間來做為暫時性儲存，浪費空間資源.

// Input： 
// null(無)

// Output： 
//  Arr[0] = 1
//  Arr[1] = 3
//  Arr[2] = 5
//  …
//  Arr[51] = 2
//  Arr[52] = 4
//  Arr[53] = 6 
//  …

#include <stdio.h>

//定義
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))   //預先定義交換函數, SWAP會交換 x 和 y的值.
#define SIZE 100    //預先定義(全域宣告): int SIZE = 100;

int main(void){

    int temp;   //交換數值時所需的第三個暫存空間
    int Arr[SIZE];

    //初始化Arr陣列中的數值：由大到小: 100~1
    int j = 0;
    for(int i = SIZE; i > 0; i--){
        Arr[j] = i;
        //printf("Arr[%d] = %d\n", j, Arr[j]);  // Testing
        j++;
    }

    //奇偶分隔
    for(int i = SIZE-1; i > 0; i--){
        for(j = i; j > 0; j-=2){    //每兩個數字進行交換
            SWAP(Arr[j], Arr[j-1], temp);   //每次交換前一位
        }
    }
    
    /*原理*/
    // Arr[] = 1 2 3 4 5 6 7 8 9 10
    // 第1圈： 2 1 4 3 6 5 8 7 10 9
    // 第2圈： 2 4 1 6 3 8 5 10 7 9
    // 第3圈： 2 4 6 1 8 3 10 5 7 9
    // 第4圈： 2 4 6 8 1 10 3 5 7 9
    // 第5圈： 2 4 6 8 10 1 3 5 7 9 //結束

    /*步驟 ------ 中括號表示 已交換的內容*/
    // Arr[] = 1 2   3 4   5 6   7 8   9 10
    // 第1圈： [2 1] [4 3] [6 5] [8 7] [10 9]
    //         |  \ /   \ /   \ /   \ /   |
    // 第2圈：  2 [4 1] [6 3] [8 5] [10 7] 9
    //         |  |  \ /   \ /   \  /  |  |
    // 第3圈：  2  4 [6 1] [8 3] [10 5] 7  9
    //         |  |  |  \  /  \  /  |  |  |
    // 第4圈：  2  4  6 [8 1] [10 3] 5  7  9
    //         |  |  |  |  \  /  |  |  |  |
    // 第5圈：  2  4  6  8  10 1  3  5  7  9 //結束 

    //由小到大排序: 由於初始化順序為：100～1，而題目要求由小到大儲存，因此Arr[50～99]由小到大排序
    for(int i = 50; i < SIZE; i++){
        for(int j = i; j < SIZE; j++){
            if(Arr[i] > Arr[j]){
                SWAP(Arr[i], Arr[j], temp); 
            }
        }
    }

    //輸出結果
    for(int i = 0; i < SIZE; i++){
        printf("Arr[%d] = %d\n", i, Arr[i]);
    }

    return 0;
}