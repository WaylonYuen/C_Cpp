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

                //優化: 略過內容中的這個單詞(str[]) -> 遇到空白 和 結束符號的判斷

                printf("%d\t比對失敗...\t%c\n", ++counter, str[position]);
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
    for (int i = 0; i < numOfResult; i++) {
        printf("index: %d\n", result[i]);
    }
    

    #pragma endregion

    return 0;
}