//
//  Lebal #007-字串<Char>
//
//  003-鍵盤輸入字元-input_Char.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 21/10/2018.
//  Last modified by Waylon.Yuen on 21/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：輸入一行文字，並列印出來。
//  操作：輸入字元
//  原理：將字元輸入 改為 字串陣列輸出
//  問題：字串大小為15，輸入超過14個字元會產生益位問題。
//  優化：X
//

#include<stdio.h>

void str_read(char str[]){
    int i=0;
    while(1){

        /*字元輸入*/
        scanf("%c", &str[i]);//等待 stdin 內的資料
        /* %c 為字元定義，此時輸入字串，由於外部有while循環，所以一樣會讀取stdin字串內容。
            不會因為 是字元輸入而無法讀取字串。

            #stdin：
                定義： 標準輸入儲存格
                原理： scanf 會等待用戶輸入內容，當用戶按下 enter，
                      用戶所輸入的內容則會儲存到 stdin 內，
                      此時 scnaf 就可以去 stdin 內讀取內容。
            */
        if(str[i] == '\n'){
            break;
        }
        i++;
    }
    /* 結尾處把‘\n’替換成’\0‘，將字元陣列 替換成 字串陣列*/
    str[i] = '\0';
}

int main(){

    char str[15];

    str_read(str);

    /*輸出字串*/
    printf("%s\n", str);

    return 0;
}