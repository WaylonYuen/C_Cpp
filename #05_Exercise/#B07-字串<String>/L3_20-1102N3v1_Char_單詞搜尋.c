// 編號：L3_20-1102N3v1_Char_單詞搜尋.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★★★☆☆ )
// 題目：單詞搜尋

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小：128MB

// 題目內容：
// 手動輸入一筆字串內容，再輸入想要查找的單詞；輸出查找到的單詞第一個字母所位於的索引值。

// 輸入： 
// 手動輸入字串

// 輸出：
// 請以 “Index: %d\n” 的格式，輸出索引結果

// Sample input :
// Winners do what losers don’t want to do.
// do

// Sample output： 
// Index: 8
// Index: 37

#include <stdio.h>

#define SIZE 100

int main(void) {

    #pragma region 宣告區

    int counter = 0;

    int position = 0;   //搜尋游標位置
    int numOfResult = 0;

    char str[SIZE] = {" "};      //內容(句子)
    char search[SIZE] = {" "};   //單詞
    int result[SIZE] = {0}; //單詞索引值

    #pragma endregion

    #pragma region 輸入區

    printf("Plz input content: \n");
    scanf("%[^\n]", str);

    printf("Search: \n");
    scanf("%s", search);

    #pragma endregion

    #pragma region 處理區

    //內容
    while (str[position] != '\0') {
        
        int i = 0;

        //標記單詞起點位置
        int index = position;

        //單詞
        while (search[i] != '\0') {

            //單詞比對
            if(str[position] == search[i]) {

                position++;

                //檢查該位置下一個字元是否為一下(符合則紀錄)
                if(search[++i] == '\0') {

                    switch (str[position]) {

                        case '\0':  //表示內容結束了,找不到就是找不到了
                        case ' ':   //表示內容段詞結束(單詞在句中)
                        case '.':   //表示內容句子結束(單詞在句末)

                            //紀錄: position - 2 是因為內容while的pos++ 和 單詞while的pos++ 一共加了2次
                            result[numOfResult++] = index;
                            break;
                    }
                }

            } else {

                do {
                    position++;
                } while (str[position] != ' ' && str[position] != '\0');

                printf("%d\t比對失敗(略過至索引: %d )...\t%c\n", ++counter, position, str[position]);
                break;
            }
        }

        position++;
    }

    #pragma endregion

    #pragma region 輸出區

    int i = 0;
    puts("\nverb\tindex");
    while(str[i] != '\0') {
        printf("%c\t%d\n", str[i], i);
        i++;
    }

    puts(" ");
    printf("搜尋結果: %d\n", numOfResult);
    for (int i = 0; i < numOfResult; i++) {
        printf("index: %d\n", result[i]);
    }
    

    #pragma endregion

    return 0;
}