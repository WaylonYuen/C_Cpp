//
//  Lebal #007-字串<Char>
//
//  004-字串緩衝區益位-String_Overflow.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 21/10/2018.
//  Last modified by Waylon.Yuen on 21/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：輸入一行文字，並列印出來，超過定義大小則截斷超出內容。
//  操作：輸入字元
//  原理：將字元輸入 改為 字串陣列輸出
//  問題：解決 Lebal #007-003 問題
//  優化：解決溢位而導致的未定義行為
//

#include<stdio.h>

void str_read(char str[], int n){

    int i;

    /*超出上限n則停止輸入，截斷內容*/
    for(i=0; i<n; i++){

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
    }
    /* 結尾處把‘\n’替換成’\0‘，將字元陣列 替換成 字串陣列*/
    str[i] = '\0';
}

int main(){

    char str[15];

    /* str定義大小為15，而輸入上限為14，因為必須為結尾‘\0’預留空間*/
    str_read(str,14);

    /*輸出字串*/
    printf("%s\n", str);

    return 0;
}