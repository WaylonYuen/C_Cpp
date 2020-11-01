//
//  Lebal #004-W01
//
//  W01-n次輸入-n_Times_inputData.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 19/10/2018.
//  Last modified by Waylon.Yuen on 19/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：輸入n個整數，並顯示出來。
//  操作：輸入n個int以EOF結束（Windows：control+Z；Mac：control+D）
//  原理：以陣列儲存n筆整數資料，並順序輸出n筆資料。
//  優化：1、限制輸入類型
//       2、限制輸入長度（防止int溢位）
//       3、限制輸入數量（最多128筆資料）
//       4、補上註解
//       5、補上流程圖
//       6、轉譯英文
//

#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int i=0,counter;
    int data;
    int A[128];

    while(scanf("%d", &data) != EOF){
        A[counter] = data;
        printf("Get data : %d\n", data);
        counter++;
    }

    puts("\n\nArray data:\n");

    for(i=0; i<counter; i++){
        printf("Data: A[%d] => %d\n", i, A[i]);
    }

    puts("\n\nEnd...\n");

    return 0;
}
