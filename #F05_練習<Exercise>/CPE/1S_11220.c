//
//  Name： 1S_11200.c
//  Version： 1.0
//	
//  Created by Waylon.Yuen on 08/07/2019.
//  Last modified by Waylon.Yuen on 08/07/2019
//  Copyright © 2019年 Oracragron. All rights reserved.
//
//  題目： Decoding the message
//          *每行為標準，為每行字串中的每個單詞取字元。
//          *第一個單詞取第一個字元、第二個單詞取第二個字元、以此類推。
//          *如果遇到單詞不足位數則忽略該次取字，保持字元變數跳到下個單詞繼續。
//              e.g: {a}s  I  p{r}eviously  pr{e}viewed     // I 因為不足兩個字元所以被略過
//              {x}: 表示取字元 x
//              Ans: are
//          *每段解碼會以空白行分隔開，請為每段解碼前加上 ”Case #n:“，其中 n 是段落編號，由 1 開始。
//

#include <stdio.h>

int main(void){

    /*Variable declaration*/
    int i; // Loop Num
    int wordPerSentence; //字串中的第N個單詞對N的暫存
    int wordNum;    //單詞中的第N個字元對N的暫存
    int titleNum, caseNum;
    char Message[1200];

    /*Set Variable*/
    titleNum = getchar(); //讀取段落編號
    getchar();  //忽略換行
    caseNum = 0;

    /*Func*/
    while(titleNum--){
        printf("Case #%d:\n", caseNum++);   //輸出Case編號
        while(gets(Message)){   //取得該行字串
            if(Message[0] == '\0')  //判斷該行是否為black，即空白行。
                break;
            for(i=0, wordPerSentence=1, wordNum=1; Message[i] != '\0'; i++, wordNum++){
                if(Message[i] == ' ')
                    wordNum = 0;
                if(wordNum == wordPerSentence){
                    printf("%c", Message[i]);
                    wordNum++;
                    wordPerSentence++;
                }
            }
            printf("\n");
        }
        if(titleNum)
            printf("\n");
    }
    return 0;
}