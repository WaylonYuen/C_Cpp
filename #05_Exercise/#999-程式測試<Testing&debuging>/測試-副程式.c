//
//  整數陣列轉換字元陣列.c
//	Version 1.0 
//	
//  Created by Waylon.Yuen on 8/111/2018.
//	Last modified by Waylon.Yuen on 8/11/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：
//	操作： 
//  問題： X
//	優化： 
//       
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE_MsgBox 64

void MsgBox_typeConversion_toChar(int* int_DataBox, char* char_MsgBox){
    int i;
    int SIZE_int_DataBox = 10;
    char getChar[2];

    memset(char_MsgBox, '\0', sizeof(&char_MsgBox)-1);//reset char_MsgBox to blank
    /* memset( Array, last char, size of blank);
        */

    for(i=0; i<SIZE_int_DataBox; i++){
            sprintf(getChar,"%d",int_DataBox[i]);// type conversion: int to char

            /*output format: A_B_C_......._n   (Assume: '_' = space)*/
            strcat(char_MsgBox," ");
            strcat(char_MsgBox,getChar);
    }
    strcat(char_MsgBox,"\0");//The last char of the string should be '\0'
}

int main(){
    
    int Data[10]={0,1,2,3,4,5,6,7,8,9};
    char MsgBox[SIZE_MsgBox];

    MsgBox_typeConversion_toChar(&Data[0], &MsgBox[0]);
    printf("%s",MsgBox);

    return 0;
}