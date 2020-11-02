#include<stdio.h>
#include "header.h"

int main (void){
    Output();
    /* 由於副程式內容在主程式之後，
        因此Output()副程式理論上是未定義行為。
        但在源文件內我們已經對Output()進行來宣告定義，
        因此Output()不會報錯。
        #此時的header.h 相當於是副程式目錄表
        */
}

/* 輸出 副程式 */
void Output(){
    printf("Hello World!\n");
}